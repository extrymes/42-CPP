/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:24:34 by sabras            #+#    #+#             */
/*   Updated: 2024/11/29 13:54:48 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include "ICharacter.hpp"
# include <iostream>

class ICharacter;

class AMateria {
	public:
		AMateria();
		AMateria(std::string const &type);
		AMateria(const AMateria &other);
		AMateria &operator=(const AMateria &other);
		virtual ~AMateria();
		std::string const &getType() const;
		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter &target);
	protected:
		std::string _type;
};

#endif
