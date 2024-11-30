/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:35:50 by sabras            #+#    #+#             */
/*   Updated: 2024/11/26 14:13:24 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "../includes/Animal.hpp"
# include "../includes/Brain.hpp"

class Dog : public Animal {
	public:
		Dog();
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		~Dog();
		std::string getType() const;
		void makeSound() const;
		void setBrain(std::string idea);
		void displayBrain() const;
	private:
		Brain *_brain;
};

#endif