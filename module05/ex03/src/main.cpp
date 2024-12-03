/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:58:45 by sabras            #+#    #+#             */
/*   Updated: 2024/12/04 00:27:40 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/Intern.hpp"
#include "../includes/colors.h"

int main() {
	std::cout << YELLOW "--- Test 1 ---" RESET << std::endl;
	Bureaucrat bob("Bob", 5);
	std::cout << BLUE << bob << RESET << std::endl;
	std::cout << YELLOW "--- Test 2 ---" RESET << std::endl;
	PresidentialPardonForm form1("Bob");
	try {
		form1.execute(bob);
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	std::cout << YELLOW "--- Test 3 ---" RESET << std::endl;
	Bureaucrat crow("Crow", 150);
	std::cout << BLUE << crow << RESET << std::endl;
	std::cout << YELLOW "--- Test 4 ---" RESET << std::endl;
	try {
		form1.execute(crow);
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	std::cout << YELLOW "--- Test 5 ---" RESET << std::endl;
	try {
		form1.beSigned(bob);
		form1.execute(bob);
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	std::cout << YELLOW "--- Test 6 ---" RESET << std::endl;
	RobotomyRequestForm form2("Bob");
	try {
		form2.beSigned(bob);
		form2.execute(bob);
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	std::cout << YELLOW "--- Test 7 ---" RESET << std::endl;
	ShrubberyCreationForm form3("Bob");
	try {
		form3.beSigned(bob);
		form3.execute(bob);
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	std::cout << YELLOW "--- Test 8 ---" RESET << std::endl;
	bob.executeForm(form3);
	std::cout << YELLOW "--- Test 9 ---" RESET << std::endl;
	crow.executeForm(form3);
	std::cout << YELLOW "--- Test 10 ---" RESET << std::endl;
	Intern intern;
	Form *form4;
	form4 = intern.makeForm("presidential pardon", "Bob");
	std::cout << BLUE << *form4 << RESET << std::endl;
	delete form4;
	std::cout << YELLOW "--- Test 11 ---" RESET << std::endl;
	form4 = intern.makeForm("robotomy request", "Bob");
	std::cout << BLUE << *form4 << RESET << std::endl;
	delete form4;
	std::cout << YELLOW "--- Test 12 ---" RESET << std::endl;
	form4 = intern.makeForm("shrubbery creation", "Bob");
	std::cout << BLUE << *form4 << RESET << std::endl;
	delete form4;
	std::cout << YELLOW "--- Test 13 ---" RESET << std::endl;
	intern.makeForm("random form", "Bob");
	return 0;
}
