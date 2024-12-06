/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 00:00:35 by sabras            #+#    #+#             */
/*   Updated: 2024/12/06 10:12:45 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
#include <iostream>
#include <stdlib.h>

Base *generate() {
	srand(time(0));
	int rd = rand() % 3;
	switch (rd) {
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
	}
	return new A();
}

void identify(Base *p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else {
		std::cout << "Unknown type" << std::endl;
	}
}

void identify(Base &p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	} catch (std::exception &) {
		try {
			(void)dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		} catch (std::exception &) {
			try {
				(void)dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
			} catch (std::exception &) {
				std::cout << "Unknown type" << std::endl;
			}
		}
	}
}

int main() {
	Base *ptr = generate();

	identify(ptr);
	identify(*ptr);
	delete ptr;
	return 0;
}
