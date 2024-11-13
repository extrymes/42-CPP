/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:15:37 by sabras            #+#    #+#             */
/*   Updated: 2024/11/13 12:32:57 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain(std::string level) {
	std::string levelNames[4] = { "debug", "info", "warning", "error" };
	void (Harl::*levels[4])() = {
		&Harl::_debug,
		&Harl::_info,
		&Harl::_warning,
		&Harl::_error
	};

	for (int i = 0; i < 4; i++)
		if (level == levelNames[i])
			return (this->*levels[i])();
}

void Harl::_debug() {
	std::cout << "This is a debug message" << std::endl;
}

void Harl::_info(void) {
	std::cout << "This is an info message" << std::endl;
}

void Harl::_warning(void) {
	std::cout << "This is a warning message" << std::endl;
}

void Harl::_error(void) {
	std::cout << "This is an error message" << std::endl;
}
