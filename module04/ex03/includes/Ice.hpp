/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:29:38 by sabras            #+#    #+#             */
/*   Updated: 2024/11/29 08:04:42 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
# include "AMateria.hpp"

class Ice : public AMateria {
	public:
		Ice();
		Ice(const Ice &other);
		Ice &operator=(const Ice &other);
		~Ice();
		AMateria *clone() const;
		void use(ICharacter &target);
};

#endif
