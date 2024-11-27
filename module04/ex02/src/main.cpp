/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:08:55 by sabras            #+#    #+#             */
/*   Updated: 2024/11/27 09:12:07 by sabras           ###   ########.fr       */
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
	AAnimal *tab[2];
	for (int i = 0; i < 1; i++) {
		tab[i] = new Dog();
		tab[i]->setBrain("This is an idea");
		tab[i]->displayBrain();
	}
	for (int i = 1; i < 2; i++) {
		tab[i] = new Cat();
		tab[i]->setBrain("This is another idea");
		tab[i]->displayBrain();
	}
	for (int i = 0; i < 2; i++)
		delete tab[i];
	Cat cat;
	cat.setBrain("This is an idea");
	Cat catCopy(cat);
	catCopy.setBrain("This is another idea");
	cat.displayBrain();
	// AAnimal animal; // object of abstract class "AAnimal" is not allowed
	return 0;
}
