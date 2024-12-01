/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 19:52:48 by sabras            #+#    #+#             */
/*   Updated: 2024/12/01 20:36:08 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/colors.h"

int main() {
	Bureaucrat bob;

	std::cout << BLUE << bob << RESET << std::endl;
	try {
		std::cout << YELLOW "Test 1" RESET << std::endl;
		bob.decreaseGrade(1); // would not work
		std::cout << BLUE << bob << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	try {
		std::cout << YELLOW "Test 2" RESET << std::endl;
		bob.increaseGrade(10);
		std::cout << BLUE << bob << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	try {
		std::cout << YELLOW "Test 3" RESET << std::endl;
		bob.increaseGrade(140); // would not work
		std::cout << BLUE << bob << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	try {
		std::cout << YELLOW "Test 4" RESET << std::endl;
		bob.increaseGrade(139);
		std::cout << BLUE << bob << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	try {
		std::cout << YELLOW "Test 5" RESET << std::endl;
		bob.decreaseGrade(10);
		std::cout << BLUE << bob << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	return 0;
}
