/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:40:04 by sabras            #+#    #+#             */
/*   Updated: 2024/12/10 13:37:24 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MutantStack.hpp"

int main()
{
	{
		std::cout << "--- Subject tests ---" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << "--- My own tests ---" << std::endl;
		MutantStack<int> mstack;
		mstack.push(0);
		mstack.push(1);
		mstack.push(2);
		mstack.push(3);
		MutantStack<int>::iterator it;
		for (it = mstack.begin(); it != mstack.end(); it++)
			std::cout << *it << std::endl;
		std::cout << "mstack.top(): " << mstack.top() << std::endl;
		std::cout << "mstack.size(): " << mstack.size() << std::endl;
		std::cout << "mstack.pop()" << std::endl;
		mstack.pop();
		for (it = mstack.begin(); it != mstack.end(); it++)
			std::cout << *it << std::endl;
	}
}
