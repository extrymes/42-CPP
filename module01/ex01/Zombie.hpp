/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:51:34 by sabras            #+#    #+#             */
/*   Updated: 2024/11/12 14:26:18 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>

class Zombie {
	public:
		Zombie(void);
		~Zombie(void);
		void announce(void);
		void setName(std::string name);
	private:
		std::string _name;
};

Zombie* zombieHorde(int N, std::string name);

#endif
