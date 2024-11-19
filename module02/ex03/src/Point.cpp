/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 00:08:40 by sabras            #+#    #+#             */
/*   Updated: 2024/11/18 16:00:24 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

Point::Point(void) : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point &other) : _x(other._x), _y(other._y) {}

Point &Point::operator=(const Point &other) {
	(void)other;
	std::cerr << "Cannot assign constant variables" << std::endl;
	return *this;
}

Point::~Point(void) {}

Fixed Point::getX(void) const {
	return _x;
}

Fixed Point::getY(void) const {
	return _y;
}
