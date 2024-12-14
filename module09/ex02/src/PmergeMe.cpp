/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:52:57 by sabras            #+#    #+#             */
/*   Updated: 2024/12/14 02:39:04 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

void fillContainers(char **seq, int size, vector &vec, deque &deq) {
	for (int i = 1; i < size; i++) {
		std::string str(seq[i]);
		if (str.empty())
			throw std::runtime_error("value cannot be empty");
		int value = convertToInteger(str);
		vector::iterator found = std::find(vec.begin(), vec.end(), value);
		if (found != vec.end())
			throw std::runtime_error("duplicate found => " + str);
		vec.push_back(value);
		deq.push_back(value);
	}
}

void mergeInsertionSort(vector &vec) {
	if (vec.size() < 2)
		return;
	// Step 1: Form pairs
	vecPairs pairedVec;
	for (size_t i = 0; i + 1 < vec.size(); i += 2)
		pairedVec.push_back(std::pair<int, int>(vec[i], vec[i + 1]));
	// Step 2: Separate the biggest and smallest for each pair
	vector biggest, smallest;
	vecPairs::iterator it;
	for (it = pairedVec.begin(); it != pairedVec.end(); it++) {
		biggest.push_back(std::max(it->first, it->second));
		smallest.push_back(std::min(it->first, it->second));
	}
	if (vec.size() % 2 != 0)
		smallest.push_back(vec.back());
	// Step 3: Sort biggest recursively
	mergeInsertionSort(biggest);
	// Step 4: Insert the smallest value associated with the smallest of the biggest
	int smallestOfBiggest = biggest.front();
	for (it = pairedVec.begin(); it != pairedVec.end(); it++) {
		if (it->first != smallestOfBiggest && it->second != smallestOfBiggest)
			continue;
		int associatedSmall = it->first == smallestOfBiggest ? it->second : it->first;
		biggest.insert(biggest.begin(), associatedSmall);
		vector::iterator associatedSmallIt = std::find(smallest.begin(), smallest.end(), associatedSmall);
		if (associatedSmallIt != smallest.end())
			smallest.erase(associatedSmallIt);
		break;
	}
	// Step 5: Insert other smallest values
	vector::iterator it2;
	for (it2 = smallest.begin(); it2 != smallest.end(); it2++) {
		int pos = binarySearch(biggest, *it2);
		biggest.insert(biggest.begin() + pos, *it2);
	}
	// Copy the sorted result to the vector
	vec = biggest;
}

void mergeInsertionSort(deque &deq) {
	if (deq.size() < 2)
		return;
	// Step 1: Form pairs
	deqPairs pairedDeq;
	for (size_t i = 0; i + 1 < deq.size(); i += 2)
		pairedDeq.push_back(std::pair<int, int>(deq[i], deq[i + 1]));
	// Step 2: Separate the biggest and smallest for each pair
	deque biggest, smallest;
	deqPairs::iterator it;
	for (it = pairedDeq.begin(); it != pairedDeq.end(); it++) {
		biggest.push_back(std::max(it->first, it->second));
		smallest.push_back(std::min(it->first, it->second));
	}
	if (deq.size() % 2 != 0)
		smallest.push_back(deq.back());
	// Step 3: Sort biggest recursively
	mergeInsertionSort(biggest);
	// Step 4: Insert the smallest value associated with the smallest of the biggest
	int smallestOfBiggest = biggest.front();
	for (it = pairedDeq.begin(); it != pairedDeq.end(); it++) {
		if (it->first != smallestOfBiggest && it->second != smallestOfBiggest)
			continue;
		int associatedSmall = it->first == smallestOfBiggest ? it->second : it->first;
		biggest.push_front(associatedSmall);
		deque::iterator associatedSmallIt = std::find(smallest.begin(), smallest.end(), associatedSmall);
		if (associatedSmallIt != smallest.end())
			smallest.erase(associatedSmallIt);
		break;
	}
	// Step 5: Insert other smallest values
	deque::iterator it2;
	for (it2 = smallest.begin(); it2 != smallest.end(); it2++) {
		int pos = binarySearch(biggest, *it2);
		biggest.insert(biggest.begin() + pos, *it2);
	}
	// Copy the sorted result to the deque
	deq = biggest;
}

int binarySearch(vector &vec, int target) {
	int low = 0, high = vec.size() - 1;
	int max = high - low + 1;
	vector jacobsthal = getJacobsthalV(max);
	int i = jacobsthal.size() - 1;
	// Jacobsthal Binary Search
	while (low <= high) {
		int mid = low + jacobsthal[i];
		if (mid > high)
			mid = high;
		if (vec[mid] == target)
			return mid;
		else if (vec[mid] < target)
			low = mid + 1;
		else
			high = mid - 1;
		if (i > 0)
			i--;
	}
	return low;
}

int binarySearch(deque &deq, int target) {
	int low = 0, high = deq.size() - 1;
	int max = high - low + 1;
	deque jacobsthal = getJacobsthalD(max);
	int i = jacobsthal.size() - 1;
	// Jacobsthal Binary Search
	while (low <= high) {
		int mid = low + jacobsthal[i];
		if (mid > high)
			mid = high;
		if (deq[mid] == target)
			return mid;
		else if (deq[mid] < target)
			low = mid + 1;
		else
			high = mid - 1;
		if (i > 0)
			i--;
	}
	return low;
}

vector getJacobsthalV(int max) {
	vector jacobsthal;
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);
	while (true) {
		int next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
		if (next > max)
			break;
		jacobsthal.push_back(next);
	}
	return jacobsthal;
}

deque getJacobsthalD(int max) {
	deque jacobsthal;
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);
	while (true) {
		int next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
		if (next > max)
			break;
		jacobsthal.push_back(next);
	}
	return jacobsthal;
}

int convertToInteger(std::string str) {
	long value;
	char *end;
	value = std::strtol(str.c_str(), &end, 10);
	if (end != str.c_str() + str.length())
		throw std::runtime_error("invalid value => " + str);
	if (value > INT_MAX)
		throw std::runtime_error("invalid integer => " + str);
	if (value < 0)
		throw std::runtime_error("not a positive number => " + str);
	return static_cast<int>(value);
}

void displayContainer(vector &vec) {
	vector::iterator it;
	for (it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void displayContainer(deque &deq) {
	deque::iterator it;
	for (it = deq.begin(); it != deq.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}
