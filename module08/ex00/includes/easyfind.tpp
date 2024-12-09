/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 09:08:31 by sabras            #+#    #+#             */
/*   Updated: 2024/12/09 09:20:00 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T &container, int toFind) {
	typename T::iterator it;
	it = std::find(container.begin(), container.end(), toFind);
	if (it == container.end())
		throw std::runtime_error("Value not found in vector");
	return it;
}
