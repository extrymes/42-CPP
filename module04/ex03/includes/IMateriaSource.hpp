/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 22:38:09 by sabras            #+#    #+#             */
/*   Updated: 2024/11/28 10:58:18 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIA_SOURCE_HPP
# define IMATERIA_SOURCE_HPP
# include "AMateria.hpp"

class IMateriaSource {
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria *) = 0;
		virtual AMateria* createMateria(std::string const &type) = 0;
};

#endif
