
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"




std::string	Forms[4] = {
	("shrubbery creation"),
	("robotomy request"),
	("presidential pardon"),
	("None")
};


Intern::Intern(void)
{
//	std::cout << "Default constructor called" << std::endl;
}

Intern::~Intern(void){

//	std::cout << "Default destructor called" << std::endl;
}

Intern::Intern(const Intern &type){
	
	*this = type;
}

Intern	&Intern::operator=(const Intern &type){

	return (*this);
}

std::string toLowerCase(const std::string &str){

	std::string result = str;

	for (size_t i = 0; i < result.length(); i++){
		if (result[i] >= 'A' && result[i] <= 'Z'){
			result[i] = result[i] + ('a' - 'A');
		}
	}
	return result;
}

AForm	*Intern::makeForm(std::string form, std::string target) const{
	
	size_t i = 0;
	std::string	formatedForm = toLowerCase(form);

	while (Forms[i] != formatedForm && i < 4 )
		i++;
	if (i >= 3)
		throw FormTypeNotFound();
	else
	{
		std::cout << "Intern creates " << formatedForm << std::endl;
		switch (i){
			
			case 0:
					return (new ShrubberyCreationForm(target));
			case 1:
					return (new RobotomyRequestForm(target));
			case 2:
					return (new PresidentialPardonForm(target));
		}
	}
	return NULL;
}
