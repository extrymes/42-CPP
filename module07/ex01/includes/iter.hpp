/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:19:26 by sabras            #+#    #+#             */
/*   Updated: 2024/12/07 16:10:18 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template <typename T>
void iter(T *arr, int len, void (*f)(T &)) {
	for (int i = 0; i < len; i++)
		f(arr[i]);
}

template <typename T>
void iter(T *arr, int len, void (*f)(T const &)) {
	for (int i = 0; i < len; i++)
		f(arr[i]);
}

template <typename T>
void print(T &value) {
	std::cout << value << std::endl;
}

#endif
