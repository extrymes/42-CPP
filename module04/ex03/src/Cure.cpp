/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:59:50 by sabras            #+#    #+#             */
/*   Updated: 2024/11/29 15:00:17 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << "Cure constructor called" << std::endl;
	_type = "cure";
}

Cure::Cure(const Cure &other) : AMateria(other) {
	std::cout << "Cure copy contructor called" << std::endl;
	*this = other;
}

Cure &Cure::operator=(const Cure &other) {
	std::cout << "Cure copy assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	_type = other._type;
	return *this;
}

Cure::~Cure() {
	std::cout << "Cure destructor called" << std::endl;
}

AMateria *Cure::clone() const {
	AMateria *newCure = new Cure();
	return newCure;
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals "<< target.getName() <<"'s wounds *" << std::endl;
}
