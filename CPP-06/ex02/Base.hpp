#pragma once

#include <string>
#include <iostream>
#include <unistd.h>
#include <cstdlib>


class	Base{

		public:
		virtual ~Base(){};
	
};	
		
Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

