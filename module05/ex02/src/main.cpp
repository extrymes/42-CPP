/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:58:45 by sabras            #+#    #+#             */
/*   Updated: 2024/12/04 16:27:10 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
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
		Bureaucrat bob("Bob", 5);
		PresidentialPardonForm form("Bob");
		bob.executeForm(form); // would not work
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	std::cout << YELLOW "--- Test 3 ---" RESET << std::endl;
	try {
		Bureaucrat crow("Crow", 150);
		std::cout << BLUE << crow << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	std::cout << YELLOW "--- Test 4 ---" RESET << std::endl;
	try {
		Bureaucrat crow("Crow", 25);
		PresidentialPardonForm form("Bob");
		crow.signForm(form);
		crow.executeForm(form); // would not work
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	std::cout << YELLOW "--- Test 5 ---" RESET << std::endl;
	try {
		Bureaucrat bob("Bob", 5);
		PresidentialPardonForm form("Bob");
		bob.signForm(form);
		bob.executeForm(form);
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	std::cout << YELLOW "--- Test 6 ---" RESET << std::endl;
	try {
		Bureaucrat bob("Bob", 5);
		RobotomyRequestForm form("Bob");
		bob.signForm(form);
		bob.executeForm(form);
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	std::cout << YELLOW "--- Test 7 ---" RESET << std::endl;
	try {
		Bureaucrat bob("Bob", 5);
		ShrubberyCreationForm form("Bob");
		bob.signForm(form);
		bob.executeForm(form);
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	std::cout << YELLOW "--- Test 8 ---" RESET << std::endl;
	try {
		Bureaucrat bob("Bob", 5);
		ShrubberyCreationForm form("Bob");
		bob.signForm(form);
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	std::cout << YELLOW "--- Test 9 ---" RESET << std::endl;
	try {
		Bureaucrat bob("Bob", 150);
		ShrubberyCreationForm form("Bob");
		bob.signForm(form); // would not work
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	std::cout << YELLOW "--- Test 10 ---" RESET << std::endl;
	try {
		Bureaucrat crow("Crow", 150);
		ShrubberyCreationForm form("Bob");
		crow.executeForm(form); // would not work
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	return 0;
}
