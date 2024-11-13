/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:16:11 by sabras            #+#    #+#             */
/*   Updated: 2024/11/13 11:28:01 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include <iostream>
#include <fstream>

static void replace_occurrences(std::string &line, std::string s1, std::string s2);
static void print_error(std::string err);

int main(int ac, char **av) {
	if (ac != 4)
		return (print_error("Usage:\n\t./program <filename> <s1> <s2>"), 1);
	std::string inFile = av[1];
	std::ifstream inputFile;
	inputFile.open(inFile.c_str());
	if (!inputFile.is_open())
		return (print_error("Cannot open file for reading"), 1);
	std::string outFile = inFile + ".replace";
	std::ofstream outputFile;
	outputFile.open(outFile.c_str());
	if (!outputFile.is_open())
		return (print_error("Cannot open file for writing"), 1);
	std::string line;
	std::string s1 = av[2];
	std::string s2 = av[3];
	while (std::getline(inputFile, line))
	{
		replace_occurrences(line, s1, s2);
		outputFile << line << std::endl;
	}
	return 0;
}

static void replace_occurrences(std::string &line, std::string s1, std::string s2) {
	size_t pos = 0;

	while ((pos = line.find(s1, pos)) != std::string::npos)
	{
		line.erase(pos, s1.length());
		line.insert(pos, s2);
		pos += s2.length();
	}
}

static void print_error(std::string err) {
	std::cerr << RED << err << RESET << std::endl;
}
