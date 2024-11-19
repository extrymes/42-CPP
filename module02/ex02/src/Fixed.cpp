/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:36:26 by sabras            #+#    #+#             */
/*   Updated: 2024/11/19 15:29:53 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed(void) {
	_rawBits = 0;
}

Fixed::Fixed(const int value) {
	_rawBits = value << _nbFracBits;
}

Fixed::Fixed(const float value) {
	_rawBits = roundf(value * (1 << _nbFracBits));
}

Fixed::Fixed(const Fixed &other) {
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
	_rawBits = other.getRawBits();
	return *this;
}

Fixed::~Fixed(void) {}

bool Fixed::operator>(const Fixed &other) {
	return _rawBits > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) {
	return _rawBits < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) {
	return _rawBits >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) {
	return _rawBits <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) {
	return _rawBits == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) {
	return _rawBits != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed &other) {
	Fixed res;
	res.setRawBits(_rawBits + other.getRawBits());
	return res;
}

Fixed Fixed::operator-(const Fixed &other) {
	Fixed res;
	res.setRawBits(_rawBits - other.getRawBits());
	return res;
}

Fixed Fixed::operator*(const Fixed &other) {
	Fixed res;
	res.setRawBits((_rawBits * other.getRawBits()) >> _nbFracBits);
	return res;
}

Fixed Fixed::operator/(const Fixed &other) {
	Fixed res;
	res.setRawBits((this->_rawBits << _nbFracBits) / other.getRawBits());
	return res;
}

Fixed &Fixed::operator++() {
	_rawBits++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	_rawBits++;
	return tmp;
}

Fixed &Fixed::operator--() {
	_rawBits--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	_rawBits--;
	return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if (a < b)
		return a;
	return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if (a > b)
		return a;
	return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

int Fixed::getRawBits(void) const {
	return _rawBits;
}

void Fixed::setRawBits(int const raw) {
	_rawBits = raw;
}

float Fixed::toFloat(void) const {
	return (float)(_rawBits / (float)(1 << _nbFracBits));
}

int Fixed::toInt(void) const {
	return _rawBits >> _nbFracBits;
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}
