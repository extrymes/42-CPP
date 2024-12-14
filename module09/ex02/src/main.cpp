/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:52:45 by sabras            #+#    #+#             */
/*   Updated: 2024/12/13 19:45:10 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

int main(int ac, char **av) {
	if (ac < 2) {
		std::cerr << RED "You must pass a positive integer sequence as argument" << std::endl;
		return 1;
	}
	vector vec;
	deque deq;
	try {
		fillContainers(av, ac, vec, deq);
		std::cout << "Before:\t";
		displayContainer(vec);
		clock_t vecStartTime = clock();
		mergeInsertionSort(vec);
		double vecElapsedTime = double(clock() - vecStartTime) / CLOCKS_PER_SEC * 1e6;
		clock_t deqStartTime = clock();
		mergeInsertionSort(deq);
		double deqElapsedTime = double(clock() - deqStartTime) / CLOCKS_PER_SEC * 1e6;
		std::cout << "After:\t";
		displayContainer(vec);
		std::cout << "Time to process a range of " << vec.size()
			<< " elements with std::vector : " << vecElapsedTime << " us" << std::endl;
		std::cout << "Time to process a range of " << deq.size()
			<< " elements with std::deque : " << deqElapsedTime << " us" << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	return 0;
}
