/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 02:54:19 by sabras            #+#    #+#             */
/*   Updated: 2024/12/06 17:16:33 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP
# include <iostream>

template <typename T>
void swap(T &a, T &b) {
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
const T &min(const T &a, const T &b) {
	if (a < b)
		return a;
	return b;
}

template <typename T>
const T &max(const T &a, const T &b) {
	if (a > b)
		return a;
	return b;
}

#endif
