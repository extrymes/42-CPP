/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 08:57:25 by sabras            #+#    #+#             */
/*   Updated: 2024/11/27 09:31:07 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP
# include <iostream>

class AAnimal {
	public:
		AAnimal();
		AAnimal(const AAnimal &other);
		AAnimal &operator=(const AAnimal &other);
		virtual ~AAnimal();
		virtual std::string getType() const = 0;
		virtual void makeSound() const = 0;
		virtual void setBrain(std::string idea) = 0;
		virtual void displayBrain() const = 0;
	protected:
		std::string _type;
};

#endif
