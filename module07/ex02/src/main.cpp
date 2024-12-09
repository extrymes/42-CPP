/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:45:08 by sabras            #+#    #+#             */
/*   Updated: 2024/12/09 08:07:57 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"

int main() {
	Array<int> tab(5);
	Array<int> otherTab;

	std::cout << "--- Initialization ---" << std::endl;
	for (unsigned int i = 0; i < tab.size(); i++)
		tab[i] = i + 1;
	for (unsigned int i = 0; i < tab.size(); i++)
		std::cout << "tab["<< i <<"]: " << tab[i] << std::endl;
	std::cout << "--- Assignment operator ---" << std::endl;
	std::cout << "otherTab = tab" << std::endl;
	otherTab = tab;
	for (unsigned int i = 0; i < otherTab.size(); i++)
		std::cout << "otherTab["<< i <<"]: " << otherTab[i] << std::endl;
	std::cout << "--- Deep copy test ---" << std::endl;
	for (unsigned int i = 0; i < otherTab.size(); i++)
		otherTab[i] = (i + 1) * 2;
	for (unsigned int i = 0; i < otherTab.size(); i++)
		std::cout << "otherTab["<< i <<"]: " << otherTab[i] << std::endl;
	for (unsigned int i = 0; i < tab.size(); i++)
		std::cout << "tab["<< i <<"]: " << tab[i] << std::endl;
	std::cout << "--- Error handling ---" << std::endl;
	try {
		tab[-1] = 0;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		tab[5] = 0;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
