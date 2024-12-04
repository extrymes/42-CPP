/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 19:52:48 by sabras            #+#    #+#             */
/*   Updated: 2024/12/04 16:16:26 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"
#include "../includes/colors.h"

int main() {
	std::cout << YELLOW "--- Test 1 ---" RESET << std::endl;
	try {
		Bureaucrat bob("Bob", 150);
		std::cout << BLUE << bob << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	std::cout << YELLOW "--- Test 2 ---" RESET << std::endl;
	try {
		Form form("MyForm", 150, 150);
		std::cout << BLUE << form << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	std::cout << YELLOW "--- Test 3 ---" RESET << std::endl;
	try {
		Bureaucrat bob("Bob", 150);
		Form form("MyForm", 150, 150);
		bob.signForm(form);
		std::cout << BLUE << form << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	std::cout << YELLOW "--- Test 4 ---" RESET << std::endl;
	try {
		Form form("MyForm", 0, 150); // would not work
		std::cout << BLUE << form << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	std::cout << YELLOW "--- Test 5 ---" RESET << std::endl;
	try {
		Form form("MyForm", 10, 151); // would not work
		std::cout << BLUE << form << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	std::cout << YELLOW "--- Test 6 ---" RESET << std::endl;
	try {
		Bureaucrat bob("Bob", 150);
		Form form("MyForm", 10, 150);
		bob.signForm(form); // would not work
		std::cout << BLUE << form << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	std::cout << YELLOW "--- Test 7 ---" RESET << std::endl;
	try {
		Bureaucrat bob("Bob", 10);
		Form form("MyForm", 10, 150);
		bob.signForm(form);
		std::cout << BLUE << form << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	return 0;
}
