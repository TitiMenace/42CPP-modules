#include "Span.hpp"



Span::Span(void){}

Span::~Span(void){}

Span::Span(unsigned int limit) : _limit(limit){}

Span::Span(const Span& copy){

	*this = copy;
}

Span &Span::operator=(const Span &type){

	_limit = type.getLimit();
	return *this; 
}

unsigned int	Span::getLimit(void) const{
	return (_limit);
}

void	Span::addNumber(int toAdd){

	if (_span.size() < _limit){
		_span.push_back(toAdd);
	}
	else
		throw LimitStorageReached();
}

void	Span::fillSpan(const std::vector<int>::iterator &begin, const std::vector<int>::iterator &end){

	std::vector<int>::iterator	it = begin;

	if ((end - begin + _span.size()) <= _limit)
		while (it < end){
			_span.push_back(*it);
			it++;
	}
	else
		throw LimitStorageReached();
}

void	Span::print(void)
{
	std::cout << "Printing Span : ";

	for(unsigned int	i = 0; i < _span.size(); i++){
		if (i + 1 == _span.size())
			std::cout << _span[i] << std::endl;
		else
			std::cout << _span[i] << "-";
	}
	std::cout << std::endl;
}
