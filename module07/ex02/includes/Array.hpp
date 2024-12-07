/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:39:45 by sabras            #+#    #+#             */
/*   Updated: 2024/12/07 15:41:53 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>
# include <stdlib.h>

template <typename T>
class Array {
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		Array &operator=(const Array &other);
		T &operator[](int idx);
		T &operator[](int idx) const;
		~Array();
		unsigned int size() const;
		class IndexOutOfBounds : public std::exception {
			public:
				virtual const char *what() const throw();
		};
	private:
		T *_array;
		unsigned int _size;
};

# include "Array.tpp"
#endif
