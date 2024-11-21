/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 22:08:17 by sabras            #+#    #+#             */
/*   Updated: 2024/11/21 16:01:08 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

int main(void) {
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	Fixed c(10.5f);
	Fixed d(2);
	std::cout << "a: " << a << std::endl;
	std::cout << "Pre-increment a: " << ++a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "Post-increment a: " << a++ << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "Pre-decrement a: " << --a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "Post-decrement a: " << a-- << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "c: " << d << std::endl;
	std::cout << "max(b, c): " << Fixed::max(b, c) << std::endl;
	std::cout << "c + d: " << c + d << std::endl;
	std::cout << "c - d: " << c - d << std::endl;
	std::cout << "c * d: " << c * d << std::endl;
	std::cout << "c / d: " << c / d << std::endl;
	return 0;
}
