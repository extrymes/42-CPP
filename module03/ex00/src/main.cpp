/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 00:12:21 by sabras            #+#    #+#             */
/*   Updated: 2024/11/20 20:42:44 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int main(void) {
	ClapTrap titan("Titan");
	ClapTrap nova("Nova");
	ClapTrap novaCopy("Nova");
	ClapTrap novaCopy2;

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
	return 0;
}
