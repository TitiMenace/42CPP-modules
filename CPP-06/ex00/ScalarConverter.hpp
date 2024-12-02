#pragma once

#include <string>
#include <cstdlib>
#include <iostream>
#include <exception>


class	ScalarConverter{

	public :
		
		ScalarConverter(void);
		virtual ~ScalarConverter(void) = 0;
	

		static	void	convert(std::string literal);
};
