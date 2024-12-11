/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 06:26:38 by sabras            #+#    #+#             */
/*   Updated: 2024/12/11 10:57:21 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

int readDataFile(dataMap &data) {
	std::ifstream file("data.csv");
	if (!file.is_open())
		throw std::runtime_error("Cannot open data file");
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line)) {
		std::string dateStr = line.substr(0, 10);
		std::string valueStr = line.substr(11);
		try {
			long long ms = convertToMilliseconds(dateStr);
			float value = std::strtof(valueStr.c_str(), NULL);
			data.insert(std::pair<long long, float>(ms, value));
		} catch (std::exception &e) {
			std::cerr << RED << e.what() << RESET << std::endl;
		}
	}
	file.close();
	return 1;
}

int readInputFile(dataMap &data, std::string filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Cannot open input file");
	std::string line;
	std::getline(file, line);
	if (line != "date | value")
		throw std::runtime_error("This file is not valid");
	while (std::getline(file, line)) {
		if (line.empty())
			continue;
		if (line.length() < 14 || line[10] != ' ' || line[11] != '|' || line[12] != ' ') {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string dateStr = line.substr(0, 10);
		std::string rateStr = line.substr(13);
		long long ms;
		float rate;
		try {
			ms = convertToMilliseconds(dateStr);
			rate = std::strtof(rateStr.c_str(), NULL);
		} catch (std::exception &) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (!checkValueLimit(rateStr)) {
			std::cout << "Error: too large a number" << std::endl;
			continue;
		}
		if (rate < 0) {
			std::cout << "Error: not a positive number" << std::endl;
			continue;
		}
		dataMap::iterator found = data.find(ms);
		if (found == data.end()) {
			found = data.lower_bound(ms);
			found--;
		}
		std::cout << dateStr << " => " << rateStr << " = " << found->second * rate << std::endl;
	}
	file.close();
	return 1;
}

std::tm convertToDate(std::string str) {
	std::tm date = {};
	std::istringstream ss(str);
	char dash;
	ss >> date.tm_year >> dash >> date.tm_mon >> dash >> date.tm_mday;
	if (ss.fail())
		throw std::runtime_error("Failed to parse date");
	if (!checkDate(date))
		throw std::runtime_error("Invalid date");
	return date;
}

long long convertToMilliseconds(std::string str) {
	std::tm date = convertToDate(str);
	std::time_t time = std::mktime(&date);
	if (time == -1)
		throw std::runtime_error("Failed to convert to time_t");
	long long ms = static_cast<long long>(time) * 1000;
	return ms;
}

bool checkDate(std::tm &date) {
	if (date.tm_year < 2009 || date.tm_year > 2024)
		return false;
	if (date.tm_mon < 1 || date.tm_mon > 12)
		return false;
	if (date.tm_year == 2009 && date.tm_mon == 1 && date.tm_mday < 2)
		return false;
	const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int days = daysInMonth[date.tm_mon - 1];
	if (date.tm_mon == 2 && isLeapYear(date.tm_year))
		days = 29;
	if (date.tm_mday < 1 || date.tm_mday > days)
		return false;
	return true;
}

bool isLeapYear(int year) {
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

bool checkValueLimit(std::string str) {
	try {
		long long value = std::strtol(str.c_str(), NULL, 10);
		return value <= 1000;
	} catch (std::exception &) {
		return false;
	}
}
