/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:29:35 by sabras            #+#    #+#             */
/*   Updated: 2024/11/29 08:04:39 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP
# include "AMateria.hpp"

class Cure : public AMateria {
	public:
		Cure();
		Cure(const Cure &other);
		Cure &operator=(const Cure &other);
		~Cure();
		AMateria *clone() const;
		void use(ICharacter &target);
};

#endif
