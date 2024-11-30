/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:59:56 by sabras            #+#    #+#             */
/*   Updated: 2024/11/30 17:14:29 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"

AMateria::AMateria() {
	std::cout << "AMateria default constructor called" << std::endl;
	_type = "default";
}

AMateria::AMateria(std::string const &type) {
	std::cout << "AMateria type constructor called" << std::endl;
	_type = type;
}

AMateria::AMateria(const AMateria &other) {
	std::cout << "AMateria copy constructor called" << std::endl;
	*this = other;
}

AMateria &AMateria::operator=(const AMateria &other) {
	std::cout << "AMateria copy assignment operator called" << std::endl;
	(void)other;
	return *this;
}

AMateria::~AMateria() {
	std::cout << "AMateria destructor called" << std::endl;
}

std::string const &AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter &) {}
