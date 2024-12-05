/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 00:44:43 by sabras            #+#    #+#             */
/*   Updated: 2024/11/06 13:41:41 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static void	addContact(PhoneBook *phoneBook);
static void	searchContact(PhoneBook *phoneBook);
static int isValidString(std::string str);
static int isNumber(std::string str);

int	main(void) {
	PhoneBook phoneBook;
	std::string input;

	std::cout << GREEN "Welcome to PhoneBook!" RESET << std::endl;
	do {
		std::cout << "Commands: " << YELLOW "ADD, SEARCH, EXIT" RESET << std::endl;
		std::cout << CYAN "Enter a command: " RESET;
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(0);
		if (input == "ADD") {
			addContact(&phoneBook);
		} else if (input == "SEARCH") {
			searchContact(&phoneBook);
		}
	} while (input != "EXIT");
	return 0;
}

static void	addContact(PhoneBook *phoneBook) {
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	do {
		std::cout << CYAN "Enter first name: " RESET;
		std::getline(std::cin, firstName);
		if (std::cin.eof())
			exit(0);
	} while (!isValidString(firstName));
	do {
		std::cout << CYAN "Enter last name: " RESET;
		std::getline(std::cin, lastName);
		if (std::cin.eof())
			exit(0);
	} while (!isValidString(lastName));
	do {
		std::cout << CYAN "Enter nickname: " RESET;
		std::getline(std::cin, nickname);
		if (std::cin.eof())
			exit(0);
	} while (!isValidString(nickname));
	do {
		std::cout << CYAN "Enter phone number: " RESET;
		std::getline(std::cin, phoneNumber);
		if (std::cin.eof())
			exit(0);
	} while (!isValidString(phoneNumber) || !isNumber(phoneNumber));
	do {
		std::cout << CYAN "Enter darkest secret: " RESET;
		std::getline(std::cin, darkestSecret);
		if (std::cin.eof())
			exit(0);
	} while (!isValidString(darkestSecret));
	phoneBook->addContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
}

static void	searchContact(PhoneBook *phoneBook) {
	std::string input;
	int index;

	if (phoneBook->getContactCount() == 0)
	{
		std::cerr << RED "No contact found" RESET << std::endl;
		return ;
	}
	phoneBook->displayList();
	do {
		std::cout << CYAN "Enter an index: " RESET;
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(0);
	} while (input == "" || input.length() > 1 || !isdigit(input[0]));
	index = input[0] - '0';
	phoneBook->searchContact(index);
}

static int isValidString(std::string str) {
	if (str.empty() || isspace(*(str.begin())) || isspace(*(str.end() - 1))
		|| str.find('\t') != std::string::npos)
		return 0;
	return 1;
}

static int isNumber(std::string str) {
	for (std::string::iterator it = str.begin(); it != str.end(); it++) {
		if (!isdigit(*it))
			return 0;
	}
	return 1;
}
