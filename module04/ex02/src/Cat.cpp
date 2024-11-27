/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:36:05 by sabras            #+#    #+#             */
/*   Updated: 2024/11/27 09:07:40 by sabras           ###   ########.fr       */
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
	*this = other;
}

Cat &Cat::operator=(const Cat &other) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other) {
		AAnimal::operator=(other);
		_brain = new Brain(*other._brain);
	}
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

std::string Cat::getType() const {
	return _type;
}

void Cat::makeSound() const {
	std::cout << "Meow..." << std::endl;
}

void Cat::setBrain(std::string idea) {
	_brain->setIdeas(idea);
}

void Cat::displayBrain() const {
	_brain->displayIdeas();
}
