/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:36:05 by sabras            #+#    #+#             */
/*   Updated: 2024/11/30 17:42:15 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat() : AAnimal() {
	std::cout << "Cat constructor called" << std::endl;
	_type = "Cat";
	_brain = new Brain();
}

Cat::Cat(const Cat &other) : AAnimal(other) {
	std::cout << "Cat copy constructor called" << std::endl;
	_brain = NULL;
	*this = other;
}

Cat &Cat::operator=(const Cat &other) {
	std::cout << "Cat copy assignment operator called" << std::endl;
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

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	if (_brain)
		delete _brain;
}

void Cat::makeSound() const {
	std::cout << "Meow..." << std::endl;
}
