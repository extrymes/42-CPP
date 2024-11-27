/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:35:50 by sabras            #+#    #+#             */
/*   Updated: 2024/11/27 09:07:32 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "../includes/AAnimal.hpp"
# include "../includes/Brain.hpp"

class Dog : public AAnimal {
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
