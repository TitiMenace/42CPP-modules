#pragma once

#include <algorithm>
#include <exception>
#include <iostream>

class	NumberNotFound	:	std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Error: Occurence not found");
		}
};

template <typename T>
typename T::iterator	easyfind(T list, int nb){

	typename T::iterator	it;

	it = std::find(list.begin(), list.end(), nb);
	if (it == list.end())
		throw NumberNotFound();
	return it;
}
