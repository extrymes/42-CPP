/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 19:29:39 by sabras            #+#    #+#             */
/*   Updated: 2024/12/01 20:31:02 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

class Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return "The grade is too high";
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return "The grade is too low";
				}
		};
		std::string getName() const;
		int getGrade() const;
		void increaseGrade(int value);
		void decreaseGrade(int value);
	private:
		const std::string _name;
		int _grade;
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &b);

#endif
