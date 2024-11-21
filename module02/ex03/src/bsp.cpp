/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 05:11:58 by sabras            #+#    #+#             */
/*   Updated: 2024/11/21 15:31:36 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

static Fixed calculateArea(Point const a, Point const b, Point const c);
static Fixed absValue(Fixed value);

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed totalArea = calculateArea(a, b, c);
	Fixed area1 = calculateArea(a, b, point);
	Fixed area2 = calculateArea(a, c, point);
	Fixed area3 = calculateArea(b, c, point);
	Fixed precision(0.00390625f);

	if (area1 == 0 || area2 == 0 || area3 == 0)
		return false;
	if (absValue(totalArea - (area1 + area2 + area3)) > precision)
		return false;
	return true;
}

static Fixed calculateArea(Point const a, Point const b, Point const c) {
	Fixed res = (a.getX() * (b.getY() - c.getY())
		+ (b.getX() * (c.getY() - a.getY()))
		+ (c.getX() * (a.getY() - b.getY())))
		/ (Fixed(2.0f));
	if (res < 0)
		res = Fixed(0) - res;
	return res;
}

static Fixed absValue(Fixed value) {
	if (value < 0)
		value = Fixed(0) - value;
	return value;
}
