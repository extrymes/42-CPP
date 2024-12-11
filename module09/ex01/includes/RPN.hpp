/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:00:24 by sabras            #+#    #+#             */
/*   Updated: 2024/12/11 16:54:23 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "colors.h"
# include <iostream>
# include <stack>
# include <exception>

typedef std::stack<float> stack;

void parseExpression(stack &st, std::string exp);
void makeOperation(stack &st, char op);
bool isValidToken(char c);
