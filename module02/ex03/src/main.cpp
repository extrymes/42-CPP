/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 23:54:03 by sabras            #+#    #+#             */
/*   Updated: 2024/11/18 16:29:39 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

int main(void) {
	Point a(0, 4);
	Point b(4, -4);
	Point c(10.25, 3.56);
	Point point(6, 2);
	bool found;

	found = bsp(a, b, c, point);
	if (found)
		std::cout << "Point found in triangle!" << std::endl;
	else
		std::cout << "Point not found in triangle!" << std::endl;
	return 0;
}
