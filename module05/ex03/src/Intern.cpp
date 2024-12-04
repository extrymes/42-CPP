/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 23:47:13 by sabras            #+#    #+#             */
/*   Updated: 2024/12/04 16:23:00 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::Intern() {
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &other) {
	std::cout << "Intern copy contructor called" << std::endl;
	(void)other;
}

Intern &Intern::operator=(const Intern &other) {
	std::cout << "Intern operator assignment called" << std::endl;
	(void)other;
	return *this;
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}

AForm *makePresidentialForm(std::string target) {
	AForm *form = new PresidentialPardonForm(target);
	return form;
}

AForm *makeRobotomyForm(std::string target) {
	AForm *form = new RobotomyRequestForm(target);
	return form;
}

AForm *makeShrubberyForm(std::string target) {
	AForm *form = new ShrubberyCreationForm(target);
	return form;
}

AForm *Intern::makeForm(std::string name, std::string target) {
	std::string formNames[3] = { "presidential pardon", "robotomy request", "shrubbery creation" };
	AForm *(*formMakers[3])(std::string) = { makePresidentialForm, makeRobotomyForm, makeShrubberyForm };
	for (int i = 0; i < 3; i++) {
		if (name == formNames[i]) {
			std::cout << GREEN "Intern creates " << name << RESET << std::endl;
			return formMakers[i](target);
		}
	}
	std::cerr << RED "Form name '"<< name <<"' does not exist" RESET << std::endl;
	return NULL;
}
