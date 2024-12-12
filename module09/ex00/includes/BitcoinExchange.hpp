/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 06:26:30 by sabras            #+#    #+#             */
/*   Updated: 2024/12/12 06:12:46 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "colors.h"
# include <iostream>
# include <stdlib.h>
# include <fstream>
# include <ctime>
# include <sstream>
# include <map>
# include <exception>
# include <limits.h>

typedef std::map<long long, float> dataMap;

void readDataFile(dataMap &data);
void readInputFile(dataMap &data, std::string filename);
std::tm convertToDate(std::string str);
long long convertToMilliseconds(std::string str);
bool checkDate(std::tm &date);
bool isLeapYear(int year);
float convertToFloat(std::string str);
