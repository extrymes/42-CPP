/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:16:50 by sabras            #+#    #+#             */
/*   Updated: 2024/11/30 17:59:57 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"
#include "../includes/Cure.hpp"
#include "../includes/MateriaSource.hpp"
#include "../includes/Character.hpp"

int main()
{
	{
		std::cout << "--- Subject tests ---" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}
	{
		std::cout << "--- My own tests ---" << std::endl;
		Character me;
		ICharacter *bob = new Character("bob");

		MateriaSource materiaSrc;
		materiaSrc.learnMateria(new Ice());
		materiaSrc.learnMateria(new Cure());
		AMateria *materia1 = materiaSrc.createMateria("ice");
		AMateria *materia2 = materiaSrc.createMateria("cure");
		AMateria *materia3 = materiaSrc.createMateria("cure"); // should not work

		me.equip(materia1);
		me.equip(materia2);
		me.equip(materia3); // should not work
		me.use(0, *bob);
		me.use(1, *bob);
		me.use(2, *bob); // should not work
		me.unequip(0);
		me.unequip(1);
		me.unequip(2); // should not work

		Character *you = new Character(me);
		materiaSrc.learnMateria(new Ice());
		AMateria *materia4 = materiaSrc.createMateria("ice");

		you->equip(materia4);
		you->use(0, *bob);
		you->use(1, *bob); // should not work

		delete you;
		delete bob;
	}
}
