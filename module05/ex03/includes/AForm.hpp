/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:07:06 by sabras            #+#    #+#             */
/*   Updated: 2024/12/04 15:54:01 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;

class AForm {
	public:
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExec);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();
		void beSigned(const Bureaucrat &b);
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
		class AFormNotSignedException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExec;
};

std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif
