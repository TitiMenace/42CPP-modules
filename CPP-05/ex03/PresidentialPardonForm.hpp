


#pragma once

#include "AForm.hpp"
#include <string>
#include <iostream>
#include <exception>
#include <fstream>


class Bureaucrat;

class	PresidentialPardonForm : public AForm{
		
	private:

		std::string	_target;
		void	beExecuted(void);


	public:

		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm &type);
		~PresidentialPardonForm(void);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &type);
		std::string	getTarget(void);
};

