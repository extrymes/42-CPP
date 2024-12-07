/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:47:09 by sabras            #+#    #+#             */
/*   Updated: 2024/12/07 15:41:08 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() {
	_array = new T[0];
	_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n) {
	_array = new T[n];
	_size = n;
}

template <typename T>
Array<T>::Array(const Array &other) {
	_array = NULL;
	*this = other;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other) {
	if (this == &other)
		return *this;
	if (_array)
		delete[] _array;
	_array = new T[other.size()];
	for (unsigned int i = 0; i < other.size(); i++)
		_array[i] = other._array[i];
	_size = other.size();
	return *this;
}

template <typename T>
T &Array<T>::operator[](int idx) {
	if (idx < 0 || idx >= (int)_size)
		throw IndexOutOfBounds();
	return _array[idx];
}

template <typename T>
T &Array<T>::operator[](int idx) const {
	if (idx < 0 || idx >= (int)_size)
		throw IndexOutOfBounds();
	return _array[idx];
}

template <typename T>
Array<T>::~Array() {
	if (_array)
		delete[] _array;
}

template <typename T>
unsigned int Array<T>::size() const {
	return _size;
}

template <typename T>
const char *Array<T>::IndexOutOfBounds::what() const throw() {
	return "Index is out of bounds";
}
