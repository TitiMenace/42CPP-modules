

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): _target("Unspecified"), AForm("RobotomyRequestForm", 72, 45)
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45){

	this->_target = target;
}

void	RobotomyRequestForm::beExecuted(void){

	std::cout << "Bzzz BZzz *Making some drilling noise*" << std::endl;

	srand(time(0));
	if (!(rand() % 2))
		std::cout << getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Error the robotomy failed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &type) : AForm(type){
	
	*this = type;
}



RobotomyRequestForm::~RobotomyRequestForm(void){

//	std::cout << "RobotomyRequestForm default destructor called" << std::endl;
}

std::string	RobotomyRequestForm::getTarget(void){
	return (this->_target);
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &type){

	this->_target = type.getIsSigned();
	return (*this);
}
