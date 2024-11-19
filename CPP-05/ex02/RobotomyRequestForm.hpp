


#pragma once

#include "AForm.hpp"
#include <string>
#include <iostream>
#include <exception>
#include <fstream>
#include <cstdlib>


class Bureaucrat;

class	RobotomyRequestForm : public AForm{
		
	private:

		std::string	_target;
		void	beExecuted(void);


	public:

		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm &type);
		~RobotomyRequestForm(void);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &type);
		std::string	getTarget(void);
};
