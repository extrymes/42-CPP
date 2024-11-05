/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:03:38 by sabras            #+#    #+#             */
/*   Updated: 2024/10/31 15:49:04 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONTACT_HPP
# define CONTACT_HPP
# include "colors.h"
# include <iostream>
# include <iomanip>

class Contact {
public:
	Contact(void);
	void setDetails(std::string firstName, std::string lastName, std::string nickname,
		std::string phoneNumber, std::string darkestSecret);
	void displayContact(void);
	void displayContactRow(int idx);
	std::string formatDisplayRow(std::string str);
private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;
};

#endif
