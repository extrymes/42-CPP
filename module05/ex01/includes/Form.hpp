/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 01:13:01 by sabras            #+#    #+#             */
/*   Updated: 2024/12/03 16:48:02 by sabras           ###   ########.fr       */
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
		~Form();
		void beSigned(Bureaucrat &b);
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
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExec;
};

std::ostream &operator<<(std::ostream &out, const Form &f);

#endif
