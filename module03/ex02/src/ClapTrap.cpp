/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 02:07:47 by sabras            #+#    #+#             */
/*   Updated: 2024/11/20 20:37:51 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap(void) {
	std::cout << "ClapTrap default constructor called" << std::endl;
	_name = "default";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name) {
	std::cout << "ClapTrap "<< name <<" constructor called" << std::endl;
	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	_name = other._name;
	return *this;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " can't attack because it is dead!" << std::endl;
		return;
	}
	if (_energyPoints == 0) {
		std::cout << "ClapTrap " << _name << " can't attack because it has no energy points left!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
		<< _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << "ClapTrap "<< _name << " can't take damage because it is dead!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
	_hitPoints -= amount;
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
		_hitPoints = 0;
	}
	_energyPoints--;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " can't repairs itself because it is dead!" << std::endl;
		return;
	}
	if (_energyPoints == 0) {
		std::cout << "ClapTrap " << _name << " can't repairs itself because it has no energy points left!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " repairs itself and recovers " << amount << " hit points!" << std::endl;
	_hitPoints += amount;
	_energyPoints--;
}
