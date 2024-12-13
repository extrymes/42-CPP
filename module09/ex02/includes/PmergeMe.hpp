/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:53:02 by sabras            #+#    #+#             */
/*   Updated: 2024/12/13 10:57:40 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "colors.h"
# include <iostream>
# include <stdlib.h>
# include <limits.h>
# include <vector>
# include <deque>
# include <algorithm>
# include <exception>

typedef std::vector<int> vector;
typedef std::deque<int> deque;
typedef std::vector<std::pair<int, int> > vecPairs;
typedef std::deque<std::pair<int, int> > deqPairs;

void fillContainers(char **seq, int size, vector &vec, deque &deq);
void mergeInsertionSort(vector &vec);
void mergeInsertionSort(deque &vec);
int binarySearch(vector &vec, int value);
int binarySearch(deque &deq, int value);
vector getJacobsthalV(int max);
deque getJacobsthalD(int max);
int convertToInteger(std::string str);
void displayContainer(vector &vec);
void displayContainer(deque &deq);
