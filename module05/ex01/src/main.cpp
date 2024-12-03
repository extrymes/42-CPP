/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 19:52:48 by sabras            #+#    #+#             */
/*   Updated: 2024/12/03 05:37:47 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"
#include "../includes/colors.h"

int main() {
	std::cout << YELLOW "--- Test 1 ---" RESET << std::endl;
	Bureaucrat bob("Bob", 150);
	std::cout << BLUE << bob << RESET << std::endl;
	std::cout << YELLOW "--- Test 2 ---" RESET << std::endl;
	Form form1("MyForm", 150, 150);
	std::cout << BLUE << form1 << RESET << std::endl;
	std::cout << YELLOW "--- Test 3 ---" RESET << std::endl;
	try {
		bob.signForm(form1);
		form1.beSigned(bob);
		std::cout << BLUE << form1 << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	try {
		std::cout << YELLOW "--- Test 4 ---" RESET << std::endl;
		Form form2("MyForm", 0, 150);
		std::cout << BLUE << form2 << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	try {
		std::cout << YELLOW "--- Test 5 ---" RESET << std::endl;
		Form form2("MyForm2", 10, 151);
		std::cout << BLUE << form2 << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	try {
		std::cout << YELLOW "--- Test 6 ---" RESET << std::endl;
		Form form3("MyForm3", 10, 150);
		bob.signForm(form3);
		form3.beSigned(bob);
		std::cout << BLUE << form3 << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	return 0;
}
