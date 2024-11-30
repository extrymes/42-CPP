/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:36:07 by sabras            #+#    #+#             */
/*   Updated: 2024/11/30 17:42:21 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog() : AAnimal() {
	std::cout << "Dog constructor called" << std::endl;
	_type = "Dog";
	_brain = new Brain();
}

Dog::Dog(const Dog &other) : AAnimal(other) {
	std::cout << "Dog copy constructor called" << std::endl;
	_brain = NULL;
	*this = other;
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	AAnimal::operator=(other);
	if (_brain)
		delete _brain;
	if (other._brain)
		_brain = new Brain(*other._brain);
	else
		_brain = NULL;
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	if (_brain)
		delete _brain;
}

void Dog::makeSound() const {
	std::cout << "Woof..." << std::endl;
}
