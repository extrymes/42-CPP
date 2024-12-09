/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 08:25:18 by sabras            #+#    #+#             */
/*   Updated: 2024/12/09 09:59:06 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <iostream>
# include <vector>
# include <list>
# include <algorithm>
# include <exception>

template <typename T>
typename T::iterator easyfind(std::vector<T> vec, int toFind);

# include "easyfind.tpp"
