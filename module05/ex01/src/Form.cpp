/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 01:13:04 by sabras            #+#    #+#             */
/*   Updated: 2024/12/04 15:58:03 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form() : _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExec(150) {
	std::cout << "Form constructor called" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExec) : _name(name), _isSigned(false),
	_gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	std::cout << "Form "<< name <<" gradeToSign "<< gradeToSign <<" gradeToExec "<< gradeToExec <<" constructor called" << std::endl;
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned),
	_gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec) {
	std::cout << "Form copy contructor called" << std::endl;
}

Form &Form::operator=(const Form &other) {
	std::cout << "Form operator assignment called" << std::endl;
	_isSigned = other._isSigned;
	return *this;
}

Form::~Form() {
	std::cout << "Form destructor called" << std::endl;
}

void Form::beSigned(const Bureaucrat &b) {
	if (_gradeToSign < b.getGrade())
		throw GradeTooLowException();
	_isSigned = true;
}

std::string Form::getName() const {
	return _name;
}

bool Form::getIsSigned() const {
	return _isSigned;
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
	out << f.getName() << ", form signed " << f.getIsSigned()
		<< " gradeToSign " << f.getGradeToSign() << " gradeToExec " << f.getGradeToExec();
	return out;
}
