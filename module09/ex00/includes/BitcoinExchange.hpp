/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 06:26:30 by sabras            #+#    #+#             */
/*   Updated: 2024/12/11 10:25:16 by sabras           ###   ########.fr       */
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

int readDataFile(dataMap &data);
int readInputFile(dataMap &data, std::string filename);
std::tm convertToDate(std::string str);
long long convertToMilliseconds(std::string str);
bool checkDate(std::tm &date);
bool isLeapYear(int year);
bool checkValueLimit(std::string str);
