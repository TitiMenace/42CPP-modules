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
		
		static 	bool	CharConverter(const std::string literal);
		static 	bool	FloatConverter(const std::string literal);
		static 	bool	DoubleConverter(const std::string literal);
		static 	bool	DecimalConverter(const std::string literal);
};
