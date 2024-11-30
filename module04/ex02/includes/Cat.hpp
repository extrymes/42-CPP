/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:34:57 by sabras            #+#    #+#             */
/*   Updated: 2024/11/27 09:07:28 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "../includes/AAnimal.hpp"
# include "../includes/Brain.hpp"

class Cat : public AAnimal {
	public:
		Cat();
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		~Cat();
		std::string getType() const;
		void makeSound() const;
		void setBrain(std::string idea);
		void displayBrain() const;
	private:
		Brain *_brain;
};

#endif