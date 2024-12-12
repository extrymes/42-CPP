/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:00:48 by sabras            #+#    #+#             */
/*   Updated: 2024/12/11 19:37:20 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

void parseExpression(stack &st, std::string exp) {
	if (exp.empty())
		throw std::runtime_error("Invalid expression");
	std::string::iterator it;
	int idx = 0;
	for (it = exp.begin(); it != exp.end(); it++) {
		if ((idx % 2 == 0 && !isValidToken(*it)) || (idx % 2 == 1 && *it != ' '))
			throw std::runtime_error("Invalid token");
		if (*it == ' ' && it + 1 == exp.end())
			throw std::runtime_error("Invalid token");
		idx++;
	}
	for (it = exp.begin(); it != exp.end(); it++) {
		if (*it == ' ')
			continue;
		if (isdigit(*it))
			st.push(*it - '0');
		else {
			if (st.size() < 2)
				throw std::runtime_error("Invalid expression");
			makeOperation(st, *it);
		}
	}
	if (st.size() > 1)
		throw std::runtime_error("Invalid expression");
}

void makeOperation(stack &st, char op) {
	float value2 = st.top();
	st.pop();
	float value1 = st.top();
	st.pop();
	float res;
	if (op == '+')
		res = value1 + value2;
	else if (op == '-')
		res = value1 - value2;
	else if (op == '/')
		res = value1 / value2;
	else if (op == '*')
		res = value1 * value2;
	st.push(res);
}

bool isValidToken(char c) {
	std::string tokens = "0123456789+-/*";
	int found = tokens.find(c);
	if (found == -1)
		return false;
	return true;
}
