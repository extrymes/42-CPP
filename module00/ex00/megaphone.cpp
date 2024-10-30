/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 23:23:11 by sabras            #+#    #+#             */
/*   Updated: 2024/10/30 15:31:31 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>

int	main(int ac, char **av)
{
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < ac; i++) {
		std::string	str(av[i]);
		for (std::string::iterator it = str.begin(); it != str.end(); it++)
			*it = std::toupper(*it);
		std::cout << str;
	}
	std::cout << std::endl;
	return (0);
}
