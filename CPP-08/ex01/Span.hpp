
#pragma once

#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>

class	LimitStorageReached :	std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Error: Integer Storage limit has been reached");
		}
};

class Span{

	public:
			Span();
			~Span();
			Span(unsigned int limit);
			Span(const Span& copy);
			Span& operator=(const Span &type);
			unsigned int		size;
			unsigned int	getLimit() const;
			void addNumber(int toAdd);
			void print(void);
			void fillSpan(const std::vector<int>::iterator &begin, const std::vector<int>::iterator &end);

	private:

			unsigned int		_limit;
			std::vector<int>	_span;

};
