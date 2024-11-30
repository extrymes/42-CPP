/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:08:55 by sabras            #+#    #+#             */
/*   Updated: 2024/11/30 16:52:33 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

int main() {
	// --- Subject tests ---
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;
	// --- My own tests ---
	Animal *tab[10];
	for (int i = 0; i < 5; i++)
		tab[i] = new Dog();
	for (int i = 5; i < 10; i++)
		tab[i] = new Cat();
	for (int i = 0; i < 10; i++)
		delete tab[i];
	return 0;
}
