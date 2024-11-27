/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:08:12 by sabras            #+#    #+#             */
/*   Updated: 2024/11/27 09:08:13 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AAnimal.hpp"

AAnimal::AAnimal() {
	std::cout << "AAnimal constructor called" << std::endl;
	_type = "AAnimal";
}

AAnimal::AAnimal(const AAnimal &other) {
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = other;
}

AAnimal &AAnimal::operator=(const AAnimal &other) {
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	_type = other._type;
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType() const {
	return _type;
}

void AAnimal::makeSound() const {
	std::cout << "Roar..." << std::endl;
}

void AAnimal::setBrain(std::string idea) {
	(void)idea;
}

void AAnimal::displayBrain() const {}
