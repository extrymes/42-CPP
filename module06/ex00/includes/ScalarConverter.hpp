/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 01:22:18 by sabras            #+#    #+#             */
/*   Updated: 2024/12/06 11:38:45 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP
# include "../includes/colors.h"
# include <iostream>
# include <cstdlib>
# include <iomanip>
# include <climits>
# include <math.h>

class ScalarConverter {
	public:
		static void *convert(std::string str);
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();
};

#endif
