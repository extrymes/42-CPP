/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:14:52 by sabras            #+#    #+#             */
/*   Updated: 2024/12/05 15:02:25 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

static void levelFilter(int index);

int main(int ac, char **av) {
	std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	if (ac != 2)
	{
		std::cout << "Usage:\n\t./harlFilter <level>" << std::endl;
		return 1;
	}
	std::string level = av[1];
	int index;
	for (index = 0; index < 4; index++)
		if (level == levels[index])
			break;
	levelFilter(index);
	return 0;
}

static void levelFilter(int index) {
	Harl harl;

	switch (index) {
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			harl.complain("debug");
			std::cout << std::endl;
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			harl.complain("info");
			std::cout << std::endl;
		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			harl.complain("warning");
			std::cout << std::endl;
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			harl.complain("error");
			std::cout << std::endl;
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
