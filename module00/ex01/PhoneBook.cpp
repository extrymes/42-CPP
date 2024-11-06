/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:21:13 by sabras            #+#    #+#             */
/*   Updated: 2024/11/06 13:41:49 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

const size_t col = 10;

PhoneBook::PhoneBook(void) : _contactCount(0) {}

void PhoneBook::addContact(std::string firstName, std::string lastName, std::string nickname,
		std::string phoneNumber, std::string darkestSecret) {
			for (int i = 7; i > 0; i--)
				this->_contacts[i] = this->_contacts[i - 1];
			this->_contacts[0].setDetails(firstName, lastName, nickname,
				phoneNumber, darkestSecret);
			if (this->_contactCount < 8)
				this->_contactCount++;
		}

void PhoneBook::displayList(void) {
	std::cout << BOLD << "|" << std::right << std::setw(col) << "index" << "|"
		<< "|" << std::setw(col) << "first name" << "|"
		<< "|" << std::setw(col) << "last name" << "|"
		<< "|" << std::setw(col) << "nickname" << "|" << std::endl;
	std::cout << "|" << std::right << std::setw(col) << "-----" << "|"
		<< "|" << std::setw(col) << "----------" << "|"
		<< "|" << std::setw(col) << "---------" << "|"
		<< "|" << std::setw(col) << "--------" << "|" << RESET << std::endl;
	for (int i = 0; i < this->_contactCount; i++)
		this->_contacts[i].displayContactRow(i);
}

void PhoneBook::searchContact(int idx) {
	if (idx >= 0 && idx < this->_contactCount)
		this->_contacts[idx].displayContact();
	else
		std::cerr << RED "Index out of range" RESET << std::endl;
}

int PhoneBook::getContactCount(void) {
	return this->_contactCount;
}
