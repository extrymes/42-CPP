/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 23:32:00 by sabras            #+#    #+#             */
/*   Updated: 2024/12/05 23:52:49 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

int main() {
	Data data;

	data.str = "Hello";
	data.value = 42;
	std::cout << "BEFORE: " << data.str << " " << data.value << std::endl;
	Data *data2 = Serializer::deserialize(Serializer::serialize(&data));
	std::cout << "AFTER: " << data2->str << " " << data2->value << std::endl;
	return 0;
}
