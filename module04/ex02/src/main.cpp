/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:08:55 by sabras            #+#    #+#             */
/*   Updated: 2024/11/30 17:00:52 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

int main() {
	// --- Subject tests ---
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	delete j;
	delete i;
	// --- My own tests ---
	AAnimal *tab[10];
	for (int i = 0; i < 5; i++)
		tab[i] = new Dog();
	for (int i = 5; i < 10; i++)
		tab[i] = new Cat();
	for (int i = 0; i < 10; i++)
		delete tab[i];
	// AAnimal animal; // object of abstract class "AAnimal" is not allowed
	return 0;
}
