/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 19:52:48 by sabras            #+#    #+#             */
/*   Updated: 2024/12/02 16:18:14 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/colors.h"

int main() {
	Bureaucrat bob;

	std::cout << YELLOW "--- Test 1 ---" RESET << std::endl;
	Bureaucrat max("Max", 5);
	try {
		std::cout << YELLOW "--- Test 2 ---" RESET << std::endl;
		Bureaucrat crow("Crow", 0); // would not work
		std::cout << BLUE << bob << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}

	std::cout << BLUE << bob << RESET << std::endl;
	try {
		std::cout << YELLOW "--- Test 3 ---" RESET << std::endl;
		bob.decrementGrade(); // would not work
		std::cout << BLUE << bob << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	try {
		std::cout << YELLOW "--- Test 4 ---" RESET << std::endl;
		bob.incrementGrade();
		std::cout << BLUE << bob << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	try {
		std::cout << YELLOW "--- Test 5 ---" RESET << std::endl;
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
	try {
		std::cout << YELLOW "--- Test 6 ---" RESET << std::endl;
		bob.incrementGrade();
		std::cout << BLUE << bob << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	try {
		std::cout << YELLOW "--- Test 7 ---" RESET << std::endl;
		bob.decrementGrade();
		std::cout << BLUE << bob << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	return 0;
}
