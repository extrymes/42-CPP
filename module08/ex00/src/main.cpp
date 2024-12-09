/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 08:25:08 by sabras            #+#    #+#             */
/*   Updated: 2024/12/09 09:26:17 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyfind.hpp"

int main() {
	int toFind[] = {0, 3, 4, 1, 9, 2};

	std::cout << "--- Vector ---" << std::endl;
	std::vector<int> vec;
	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	for (int i = 0; i < 6; i++) {
		std::cout << "easyfind("<< toFind[i] <<"): ";
		try {
			easyfind(vec, toFind[i]);
			std::cout << "OK" << std::endl;
		} catch (std::exception &) {
			std::cout << "NOT FOUND" << std::endl;
		}
	}
	std::cout << "--- List ---" << std::endl;
	std::list<int> lst;
	lst.push_back(0);
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	for (int i = 0; i < 6; i++) {
		std::cout << "easyfind("<< toFind[i] <<"): ";
		try {
			easyfind(lst, toFind[i]);
			std::cout << "OK" << std::endl;
		} catch (std::exception &) {
			std::cout << "NOT FOUND" << std::endl;
		}
	}
	return 0;
}
