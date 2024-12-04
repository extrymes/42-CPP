/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 19:52:48 by sabras            #+#    #+#             */
/*   Updated: 2024/12/04 11:14:10 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/colors.h"

int main() {
	std::cout << YELLOW "--- Test 1 ---" RESET << std::endl;
	try {
		Bureaucrat bob("Bob", 5);
		std::cout << BLUE << bob << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	std::cout << YELLOW "--- Test 2 ---" RESET << std::endl;
	try {
		Bureaucrat crow("Crow", 0); // would not work
		std::cout << BLUE << crow << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	std::cout << YELLOW "--- Test 3 ---" RESET << std::endl;
	try {
		Bureaucrat bob("Bob", 150);
		bob.decrementGrade(); // would not work
		std::cout << BLUE << bob << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	std::cout << YELLOW "--- Test 4 ---" RESET << std::endl;
	try {
		Bureaucrat bob("Bob", 5);
		bob.incrementGrade();
		std::cout << BLUE << bob << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	std::cout << YELLOW "--- Test 5 ---" RESET << std::endl;
	try {
		Bureaucrat max("Max", 5);
		max.incrementGrade();
		std::cout << BLUE << max << RESET << std::endl;
		max.incrementGrade();
		std::cout << BLUE << max << RESET << std::endl;
		max.incrementGrade();
		std::cout << BLUE << max << RESET << std::endl;
		max.incrementGrade();
		std::cout << BLUE << max << RESET << std::endl;
		max.incrementGrade(); // would not work
		std::cout << BLUE << max << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	std::cout << YELLOW "--- Test 6 ---" RESET << std::endl;
	try {
		Bureaucrat bob("Bob", 5);
		bob.incrementGrade();
		std::cout << BLUE << bob << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	std::cout << YELLOW "--- Test 7 ---" RESET << std::endl;
	try {
		Bureaucrat bob("Bob", 4);
		bob.decrementGrade();
		std::cout << BLUE << bob << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	return 0;
}
