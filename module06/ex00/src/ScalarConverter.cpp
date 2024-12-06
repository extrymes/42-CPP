/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 01:22:50 by sabras            #+#    #+#             */
/*   Updated: 2024/12/06 14:01:48 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

bool isChar(std::string str) {
	return (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]));
}

bool isInt(std::string str) {
	if (str.empty())
		return false;
	size_t i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (i == str.size())
		return false;
	for (; i < str.size(); i++)
		if (!std::isdigit(str[i]))
			return false;
	return true;
}

bool isFloat(std::string str) {
	if (str.empty())
		return false;
	size_t i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (i == str.size())
		return false;
	bool hasDigits = false;
	bool hasDot = false;
	bool hasIndicator = false;
	for (; i < str.size(); i++) {
		if (std::isdigit(str[i]))
			hasDigits = true;
		else if (str[i] == '.') {
			if (hasDot || i == 0 || !isdigit(str[i + 1]))
				return false;
			hasDot = true;
		} else if (str[i] == 'f') {
			if (hasIndicator || str[i + 1])
				return false;
			hasIndicator = true;
		} else return false;
	}
	return hasDigits && hasDot && hasIndicator;
}

bool isDouble(std::string str) {
	if (str.empty())
		return false;
	size_t i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (i == str.size())
		return false;
	bool hasDigits = false;
	bool hasDot = false;
	for (; i < str.size(); i++) {
		if (std::isdigit(str[i]))
			hasDigits = true;
		else if (str[i] == '.') {
			if (hasDot || i == 0 || !isdigit(str[i + 1]))
				return false;
			hasDot = true;
		} else return false;
	}
	return hasDigits && hasDot;
}

bool checkLength(std::string str) {
	int len = 0;

	for (std::string::iterator it = str.begin(); it != str.end(); it++)
		if (isdigit(*it) || *it == '.')
			len++;
	return len < 11;
}

void printChar(std::string str) {
	char c = *str.c_str();

	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void printInt(std::string str) {
	long value = std::strtol(str.c_str(), NULL, 10);

	if (value < INT_MIN || value > INT_MAX) {
		std::cerr << RED "Invalid number" RESET << std::endl;
		return;
	}
	if (value < 32 || value > 126)
		std::cout << "char: non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "int: " << value << std::endl;
	std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void printFloat(std::string str) {
	if (!checkLength(str)) {
		std::cerr << RED "Invalid number" RESET << std::endl;
		return;
	}
	float value = std::strtof(str.c_str(), NULL);
	if (static_cast<int>(value) < 32 || static_cast<int>(value) > 126)
		std::cout << "char: non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(value) << std::endl;
	if (value == floor(value))
		std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << value << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void printDouble(std::string str) {
	if (!checkLength(str)) {
		std::cerr << RED "Invalid number" RESET << std::endl;
		return;
	}
	double value = std::strtod(str.c_str(), NULL);
	if (static_cast<int>(value) < 32 || static_cast<int>(value) > 126)
		std::cout << "char: non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(value) << std::endl;
	if (value == floor(value))
		std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << value << std::endl;
}

bool handleSpecial(std::string str) {
	if (str == "nan" || str == "nanf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return true;
	}
	if (str == "inf" || str == "inff" || str == "+inf" || str == "+inff"
		|| str == "-inf" || str == "-inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (str == "-inf" || str == "-inff") {
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
		} else {
			std::cout << "float: inff" << std::endl;
			std::cout << "double: inf" << std::endl;
		}
		return true;
	}
	return false;
}

void *ScalarConverter::convert(std::string str) {
	if (handleSpecial(str))
		return (NULL);
	if (isChar(str))
		printChar(str);
	else if (isInt(str))
		printInt(str);
	else if (isFloat(str))
		printFloat(str);
	else if (isDouble(str))
		printDouble(str);
	else
		std::cerr << RED "Unknown type" RESET << std::endl;
	return (NULL);
}
