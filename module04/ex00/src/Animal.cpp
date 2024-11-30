/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:31:15 by sabras            #+#    #+#             */
/*   Updated: 2024/11/30 16:46:19 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal() {
	std::cout << "Animal constructor called" << std::endl;
	_type = "Animal";
}

Animal::Animal(const Animal &other) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = other;
}

Animal &Animal::operator=(const Animal &other) {
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	_type = other._type;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const {
	return _type;
}

void Animal::makeSound() const {
	std::cout << "This is default sound..." << std::endl;
}
