

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): _target("Unspecified"), AForm("PresidentialPardonForm", 25, 5)
{
	return;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5){

	this->_target = target;
}

void	PresidentialPardonForm::beExecuted(void){

	std::string	target;
	target = this->getTarget();

	std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}



PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &type) : AForm(type){
	
	*this = type;
}



PresidentialPardonForm::~PresidentialPardonForm(void){

//	std::cout << "PresidentialPardonForm default destructor called" << std::endl;
}

std::string	PresidentialPardonForm::getTarget(void){
	return (this->_target);
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &type){

	this->_target = type.getIsSigned();
	return (*this);
}
