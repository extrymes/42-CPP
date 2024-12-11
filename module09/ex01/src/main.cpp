/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:00:32 by sabras            #+#    #+#             */
/*   Updated: 2024/12/11 16:51:35 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << RED "Usage:\n\t./RPN <expression>" RESET << std::endl;
		return 1;
	}
	stack st;
	try {
		parseExpression(st, av[1]);
		std::cout << st.top() << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	return 0;
}
