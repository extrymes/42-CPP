/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:15:34 by sabras            #+#    #+#             */
/*   Updated: 2024/11/13 12:30:35 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include <iostream>

class Harl {
	public:
		void complain(std::string level);
	private:
		void _debug(void);
		void _info(void);
		void _warning(void);
		void _error(void);
};

#endif
