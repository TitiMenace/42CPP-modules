#pragma once

#include <string>
#include <iostream>

#include "ABC.hpp"

class	Base{

	public:
			virtual ~Base();
	
	private:
		
			Base();
			Base*	generate(void);
			void	identify(Base* p);
			void	identify(Base& p);
};
