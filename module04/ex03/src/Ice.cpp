/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:59:51 by sabras            #+#    #+#             */
/*   Updated: 2024/11/29 15:00:23 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "Ice constructor called" << std::endl;
	_type = "ice";
}

Ice::Ice(const Ice &other) : AMateria(other) {
	std::cout << "Ice copy constructor called" << std::endl;
	*this = other;
}

Ice &Ice::operator=(const Ice &other) {
	std::cout << "Ice copy assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	_type = other._type;
	return *this;
}

Ice::~Ice() {
	std::cout << "Ice destructor called" << std::endl;
}

AMateria *Ice::clone() const {
	AMateria *newIce = new Ice();
	return newIce;
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice at "<< target.getName() <<" *" << std::endl;
}
