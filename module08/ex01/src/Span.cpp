/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:15:08 by sabras            #+#    #+#             */
/*   Updated: 2024/12/10 13:28:54 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

Span::Span() {
	_size = 0;
	_maxSize = 0;
}

Span::Span(unsigned int N) {
	_size = 0;
	_maxSize = N;
}

Span::Span(const Span &other) {
	*this = other;
}

Span &Span::operator=(const Span &) {
	return *this;
}

Span::~Span() {}

void Span::addNumber(int nb) {
	if (_size + 1 > _maxSize)
		throw std::runtime_error("Limit reached: cannot add number");
	_vec.push_back(nb);
	_size++;
}

void Span::fill(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (end < begin)
		throw std::runtime_error("The range of iterators is invalid");
	unsigned int rangeSize = end - begin;
	if (_size + rangeSize > _maxSize)
		throw std::runtime_error("Limit reached: cannot fill");
	_vec.insert(_vec.end(), begin, end);
	_size += rangeSize;
}

int Span::shortestSpan() {
	if (_size < 2)
		throw std::runtime_error("There must be at least 2 numbers to find the shortest span");
	int shortest = -1;
	std::vector<int> sortedVec = _vec;
	std::sort(sortedVec.begin(), sortedVec.end());
	for (unsigned int i = 1; i < _size; i++) {
		int diff = sortedVec[i] - sortedVec[i - 1];
		if (diff < shortest || shortest == -1)
			shortest = diff;
	}
	return shortest;
}

int Span::longestSpan() {
	if (_size < 2)
		throw std::runtime_error("There must be at least 2 numbers to find the longest span");
	std::vector<int>::iterator minIt = std::min_element(_vec.begin(), _vec.end());
	std::vector<int>::iterator maxIt = std::max_element(_vec.begin(), _vec.end());
	if (minIt == _vec.end())
		throw std::runtime_error("Cannot find the iterator to the minimum element");
	if (maxIt == _vec.end())
		throw std::runtime_error("Cannot find the iterator to the maximum element");
	return *maxIt - *minIt;
}
