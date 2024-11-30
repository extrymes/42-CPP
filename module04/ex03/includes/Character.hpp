/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 23:11:34 by sabras            #+#    #+#             */
/*   Updated: 2024/11/30 15:44:31 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"

class Character : public ICharacter {
	public:
		Character();
		Character(std::string name);
		Character(const Character &other);
		Character &operator=(const Character &other);
		~Character();
		std::string const &getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
	private:
		std::string _name;
		AMateria *_inventory[4];
		AMateria *_floor[128];
};

#endif
