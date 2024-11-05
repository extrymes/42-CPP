/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:13:03 by sabras            #+#    #+#             */
/*   Updated: 2024/10/31 20:01:02 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

const size_t col = 10;

Contact::Contact() : _firstName(""), _lastName(""), _nickname(""),
	_phoneNumber(""), _darkestSecret("") {}

void Contact::setDetails(std::string firstName, std::string lastName, std::string nickname,
		std::string phoneNumber, std::string darkestSecret) {
			this->_firstName = firstName;
			this->_lastName = lastName;
			this->_nickname = nickname;
			this->_phoneNumber = phoneNumber;
			this->_darkestSecret = darkestSecret;
		}

void Contact::displayContact(void) {
	std::cout << BOLD "First name: " RESET << Contact::_firstName << std::endl;
	std::cout << BOLD "Last name: " RESET << Contact::_lastName << std::endl;
	std::cout << BOLD "Nickname: " RESET << Contact::_nickname << std::endl;
	std::cout << BOLD "Phone number: " RESET << Contact::_phoneNumber << std::endl;
	std::cout << BOLD "Darkest secret: " RESET << Contact::_darkestSecret << std::endl;
}

void Contact::displayContactRow(int idx) {
	std::cout << "|" << std::right << std::setw(col) << idx << "|"
		<< "|" << std::setw(col) << formatDisplayRow(Contact::_firstName) << "|"
		<< "|" << std::setw(col) << formatDisplayRow(Contact::_lastName) << "|"
		<< "|" << std::setw(col) << formatDisplayRow(Contact::_nickname) << "|" << std::endl;
}

std::string Contact::formatDisplayRow(std::string str) {
	if (str.length() > col)
		return str.substr(0, col - 1) + '.';
	return str;
}
