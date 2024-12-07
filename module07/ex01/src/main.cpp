/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:21:00 by sabras            #+#    #+#             */
/*   Updated: 2024/12/07 16:10:25 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"

int main() {
	int arr[] = {0, 1, 2, 3};
	std::string arr2[] = {"Hello", "World"};

	iter(arr, 4, print<int>);
	iter(arr2, 2, print<std::string>);
	return 0;
}
