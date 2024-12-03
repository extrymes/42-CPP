/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 23:58:59 by sabras            #+#    #+#             */
/*   Updated: 2024/12/04 00:21:21 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;

class Form {
	public:
		Form();
		Form(std::string name, int gradeToSign, int gradeToExec);
		Form(const Form &other);
		Form &operator=(const Form &other);
		virtual ~Form();
		void beSigned(Bureaucrat &b);
		void checkIsExecutable(Bureaucrat const &executor) const;
		virtual void execute(Bureaucrat const &executor) const = 0;
		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExec() const;
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class FormNotSignedException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExec;
};

std::ostream &operator<<(std::ostream &out, const Form &f);

#endif
