/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:50:37 by sabras            #+#    #+#             */
/*   Updated: 2024/12/05 14:52:36 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int main(void) {
	Zombie *zombie = newZombie("Simon");
	zombie->announce();
	delete zombie;
	randomChump("Maxime");
	return 0;
}
