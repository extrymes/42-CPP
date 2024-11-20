/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 03:41:46 by sabras            #+#    #+#             */
/*   Updated: 2024/11/19 15:48:21 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

int main(void) {
	FragTrap titan("Titan");
	FragTrap nova("Nova");
	FragTrap novaCopy("Nova");
	FragTrap novaCopy2;

	novaCopy2 = nova;
	titan.attack("Nova");
	nova.takeDamage(30);

	titan.attack("Nova");
	nova.takeDamage(30);

	titan.attack("Nova");
	nova.takeDamage(30);
	nova.beRepaired(1);
	novaCopy.beRepaired(1);
	novaCopy2.beRepaired(1);

	titan.highFivesGuys();
	return 0;
}
