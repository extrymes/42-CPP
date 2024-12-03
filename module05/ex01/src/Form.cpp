/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 01:13:04 by sabras            #+#    #+#             */
/*   Updated: 2024/12/03 05:28:59 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form() : _name("default"), _signed(0), _gradeToSign(150), _gradeToExec(150) {
	std::cout << "Form constructor called" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExec) : _name(name), _signed(0),
	_gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	std::cout << "Form "<< name <<" gradeToSign "<< gradeToSign <<" gradeToExec "<< gradeToExec <<" constructor called" << std::endl;
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other) : _name(other._name),
	_gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec) {
	std::cout << "Form copy contructor called" << std::endl;
	*this = other;
}

Form &Form::operator=(const Form &other) {
	std::cout << "Form operator assignment called" << std::endl;
	_signed = other._signed;
	return *this;
}

Form::~Form() {
	std::cout << "Form destructor called" << std::endl;
}

void Form::beSigned(Bureaucrat &b) {
	if (_gradeToSign < b.getGrade())
		throw GradeTooLowException();
	_signed = 1;
}

std::string Form::getName() const {
	return _name;
}

int Form::getSigned() const {
	return _signed;
}

int Form::getGradeToSign() const {
	return _gradeToSign;
}

int Form::getGradeToExec() const {
	return _gradeToExec;
}

const char *Form::GradeTooHighException::what() const throw() {
	return "The grade is too high";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "The grade is too low";
}

std::ostream &operator<<(std::ostream &out, const Form &f) {
	out << f.getName() << ", form signed " << f.getSigned()
		<< " gradeToSign " << f.getGradeToSign() << " gradeToExec " << f.getGradeToExec();
	return out;
}
