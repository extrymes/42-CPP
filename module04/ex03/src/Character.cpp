/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 23:11:31 by sabras            #+#    #+#             */
/*   Updated: 2024/11/30 16:07:20 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

Character::Character() : ICharacter() {
	std::cout << "Character constructor called" << std::endl;
	_name = "default";
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < 128; i++)
		_floor[i] = NULL;
}

Character::Character(std::string name) : ICharacter() {
	std::cout << "Character name constructor called" << std::endl;
	_name = name;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < 128; i++)
		_floor[i] = NULL;
}

Character::Character(const Character &other) : ICharacter(other) {
	std::cout << "Character copy constructor called" << std::endl;
	_name = other._name;
	for (int i = 0; i < 4; i++)
		_inventory[i] = other._inventory[i] ? other._inventory[i]->clone() : NULL;
	for (int i = 0; i < 128; i++)
		_floor[i] = other._floor[i] ? other._floor[i]->clone() : NULL;
}

Character &Character::operator=(const Character &other) {
	std::cout << "Character copy assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	_name = other._name;
	for (int i = 0; i < 4; i++) {
		if (_inventory[i])
			delete _inventory[i];
		_inventory[i] = other._inventory[i] ? other._inventory[i]->clone() : NULL;
	}
	for (int i = 0; i < 128; i++) {
		if (_floor[i])
			delete _floor[i];
		_floor[i] = other._floor[i] ? other._floor[i]->clone() : NULL;
	}
	return *this;
}

Character::~Character() {
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
			delete _inventory[i];
	for (int i = 0; i < 128; i++)
		if (_floor[i])
			delete _floor[i];
}

std::string const &Character::getName() const {
	return _name;
}

void Character::equip(AMateria *m) {
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
		if (_inventory[i] == m)
			return;
	for (int i = 0; i < 4; i++) {
		if (!_inventory[i]) {
			_inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3 || !_inventory[idx])
		return;
	for (int i = 0; i < 128; i++)
		if (_floor[i] == _inventory[idx])
			return;
	for (int i = 0; i < 128; i++) {
		if (!_floor[i]) {
			_floor[i] = _inventory[idx];
			break;
		}
	}
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx > 3 || !_inventory[idx])
		return;
	_inventory[idx]->use(target);
}
