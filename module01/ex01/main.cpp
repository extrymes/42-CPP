/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:25:24 by sabras            #+#    #+#             */
/*   Updated: 2024/11/12 14:35:35 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
	Zombie *zombies;
	int N = 5;

	zombies = zombieHorde(N, "Slurpy");
	for (int i = 0; i < N; i++)
		zombies[i].announce();
	delete zombies;
	return 0;
}
