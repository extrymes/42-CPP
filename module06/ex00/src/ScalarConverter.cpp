/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 01:22:50 by sabras            #+#    #+#             */
/*   Updated: 2024/12/05 23:53:41 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"
# include <iostream>
# include <iomanip>

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
	if (i == str.size() || str.back() != 'f')
		return false;
	bool hasDot = false;
	bool hasDigits = false;
	for (; i < str.size(); i++) {
		if (std::isdigit(str[i]))
			hasDigits = true;
		else if (str[i] == '.' && !hasDot)
			hasDot = true;
		else if (str[i] != 'f')
			return false;
	}
	return hasDigits && hasDot;
}

bool isDouble(std::string str) {
	if (str.empty())
		return false;
	size_t i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (i == str.size())
		return false;
	bool hasDot = false;
	bool hasDigits = false;
	for (; i < str.size(); i++) {
		if (std::isdigit(str[i]))
			hasDigits = true;
		else if (str[i] == '.' && !hasDot)
			hasDot = true;
		else return false;
	}
	return hasDigits && hasDot;
}

void printChar(std::string str) {
	char c = *str.c_str();

	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void printInt(std::string str) {
	int value = std::atoi(str.c_str());

	if (value < 32 || value > 126)
		std::cout << "char: not displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	std::cout << "int: " << value << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void printFloat(std::string str) {
	float value = std::strtof(str.c_str(), NULL);

	if (static_cast<int>(value) < 32 || static_cast<int>(value) > 126)
		std::cout << "char: not displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << value << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void printDouble(std::string str) {
	double value = std::atof(str.c_str());

	if (static_cast<int>(value) < 32 || static_cast<int>(value) > 126)
		std::cout << "char: not displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
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
		std::cerr << RED "Invalid type" RESET << std::endl;
	return (NULL);
}
