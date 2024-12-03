/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:58:38 by sabras            #+#    #+#             */
/*   Updated: 2024/12/03 19:12:17 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

AForm::AForm() : _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExec(150) {
	std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExec) : _name(name), _isSigned(false),
	_gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	std::cout << "AForm "<< name <<" gradeToSign "<< gradeToSign <<" gradeToExec "<< gradeToExec <<" constructor called" << std::endl;
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExec > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other) : _name(other._name), _isSigned(other._isSigned),
	_gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec) {
	std::cout << "AForm copy contructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other) {
	std::cout << "AForm operator assignment called" << std::endl;
	_isSigned = other._isSigned;
	return *this;
}

AForm::~AForm() {
	std::cout << "AForm destructor called" << std::endl;
}

void AForm::beSigned(Bureaucrat &b) {
	if (_gradeToSign < b.getGrade())
		throw GradeTooLowException();
	_isSigned = true;
}

void AForm::checkIsExecutable(Bureaucrat const &executor) const {
	if (!_isSigned)
		throw FormNotSignedException();
	if (_gradeToExec < executor.getGrade())
		throw GradeTooLowException();
}

std::string AForm::getName() const {
	return _name;
}

bool AForm::getIsSigned() const {
	return _isSigned;
}

int AForm::getGradeToSign() const {
	return _gradeToSign;
}

int AForm::getGradeToExec() const {
	return _gradeToExec;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "The grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "The grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw() {
	return "The form is not signed";
}

std::ostream &operator<<(std::ostream &out, const AForm &f) {
	out << f.getName() << ", form signed " << f.getIsSigned()
		<< " gradeToSign " << f.getGradeToSign() << " gradeToExec " << f.getGradeToExec();
	return out;
}
