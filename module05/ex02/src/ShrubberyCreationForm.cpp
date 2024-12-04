/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:08:33 by sabras            #+#    #+#             */
/*   Updated: 2024/12/04 10:47:02 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137),
	_target("default") {
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137),
	_target(target) {
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other),
	_target(other._target) {
	std::cout << "ShrubberyCreationForm copy contructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	std::cout << "ShrubberyCreationForm operator assignment called" << std::endl;
	if (this == &other)
		return *this;
	AForm::operator=(other);
	_target = other._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	checkIsExecutable(executor);
	std::ofstream file(std::string(_target + "_shrubbery").c_str());
	if (!file.is_open()) {
		std::cerr << RED "Cannot open file" RESET << std::endl;
		return;
	}
	file << "\t\t\t,@@@@@@@,\n\
\t,,,.   ,@@@@@@/@@,  .oo8888o.\n\
 ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n\
,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n\
%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n\
%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n\
`&%\\ ` /%&'    |.|        \\ '|8'\n\
\t|o|        | |         | |\n\
\t|.|        | |         | |\n\
\t\\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
	file.close();
}

