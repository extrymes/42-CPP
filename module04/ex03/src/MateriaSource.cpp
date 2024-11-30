/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 23:02:09 by sabras            #+#    #+#             */
/*   Updated: 2024/11/30 15:48:19 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource() {
	std::cout << "MateriaSource constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other) : IMateriaSource(other) {
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_templates[i] = other._templates[i] ? other._templates[i]->clone() : NULL;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
	std::cout << "MateriaSource copy assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	for (int i = 0; i < 4; i++) {
		if (_templates[i])
			delete _templates[i];
		_templates[i] = other._templates[i] ? other._templates[i]->clone() : NULL;
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		if (_templates[i])
			delete _templates[i];
}

void MateriaSource::learnMateria(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (!_templates[i]) {
			_templates[i] = m;
			break;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type) {
	AMateria *tmp;

	for (int i = 3; i >= 0; i--) {
		if (_templates[i] && _templates[i]->getType() == type) {
			tmp = _templates[i];
			_templates[i] = NULL;
			return tmp;
		}
	}
	return NULL;
}
