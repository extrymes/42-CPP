/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 03:41:46 by sabras            #+#    #+#             */
/*   Updated: 2024/11/15 04:36:32 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

int main(void) {
	ScavTrap titan("Titan");
	ScavTrap nova("Nova");
	ScavTrap novaCopy("Nova");
	ScavTrap novaCopy2;

	novaCopy2 = nova;
	titan.attack("Nova");
	nova.takeDamage(5);

	titan.attack("Nova");
	nova.takeDamage(5);

	titan.attack("Nova");
	nova.takeDamage(1);
	nova.beRepaired(1);
	novaCopy.beRepaired(1);
	novaCopy2.beRepaired(1);

	titan.guardGate();
	return 0;
}
