/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 23:54:03 by sabras            #+#    #+#             */
/*   Updated: 2024/11/21 15:57:51 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

int main( void ) {
	Point a(0, 4);
	Point b(4, -4);
	Point c(10.25, 3.56);
	float x[] = {2, 0};
	float y[] = {2, 6, 10, 14, 0, 2, 4, 8};
	int j = 0;
	int i = 0;

	while (i < 8)
	{
		Point d(y[i], x[j]);
		std::cout << "y = " << y[i] << std::endl;
		std::cout << "x = " << x[j] << std::endl;
		if (bsp(a, b, c, d))
			std::cout << "YES, your point is within the triangle!" << std::endl;
		else
			std::cout << "NO, your point is not within the triangle!" << std::endl;
		i++;
		if (i == 4 && j == 0)
			j = 1;
	}
	return 0;
}
