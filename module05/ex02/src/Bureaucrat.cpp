/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 19:43:41 by sabras            #+#    #+#             */
/*   Updated: 2024/12/03 23:34:08 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	std::cout << "Bureaucrat "<< name <<" grade "<< grade <<" constructor called" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {
	std::cout << "Bureaucrat copy contructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	std::cout << "Bureaucrat operator assignment called" << std::endl;
	_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::incrementGrade() {
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade() {
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(const AForm &form) {
	if (_grade <= form.getGradeToSign())
		std::cout << _name << " signed " << form.getName() << std::endl;
	else
		std::cout << _name << " couldn't sign "
			<< form.getName() << " because his grade is too low!" << std::endl;
}

void Bureaucrat::executeForm(const AForm &form) {
	if (_grade <= form.getGradeToExec())
		std::cout << _name << " executed " << form.getName() << std::endl;
	else
		std::cout << _name << " couldn't execute "
			<< form.getName() << " because his grade is too low!" << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "The grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "The grade is too low";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b) {
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return out;
}

