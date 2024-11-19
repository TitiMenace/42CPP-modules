
#include "AForm.hpp"
#include "Bureaucrat.hpp"


AForm::AForm(void) : _name("no_name"), _is_signed(false), _grade_to_sign(1), _grade_to_exec(2)
{
//	std::cout << "AForm default constructor called" << std::endl;
}



AForm::AForm(std::string name, const int grade_to_sign, const int grade_to_exec) : _name(name), _is_signed(false), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec){

	if (grade_to_sign < 1 || grade_to_exec < 1)
		throw GradeTooHighException();
	else if (grade_to_sign > 150 || grade_to_exec > 150)
		throw GradeTooLowException();
}

AForm::AForm(AForm &type) : _name(type._name), _grade_to_sign(type._grade_to_sign), _grade_to_exec(type._grade_to_exec){
	
	*this = type;
}

AForm::~AForm(void){

//	std::cout << "AForm default destructor called" << std::endl;
}

AForm	&AForm::operator=(const AForm &type){

//	this->_grade_to_sign = type.getGradeToSign();
//	this->_grade_to_exec = type.getGradeToExec();
	this->_is_signed = type.getIsSigned();
	return (*this);
}

std::ostream	&operator<<(std::ostream &stream, const AForm &form){
	
	stream << form.getName();
	if (form.getIsSigned())
		stream << " is signed";
	else
		stream << " is not signed";
	stream << ": grade to sign = " << form.getGradeToSign() << " grade to exec = " << form.getGradeToExec() << std::endl;
	return stream;
}

std::string	AForm::getName(void) const{

	return (this->_name);
}

int		AForm::getGradeToSign(void) const{

	return this->_grade_to_sign;
}

int		AForm::getGradeToExec(void) const{

	return this->_grade_to_exec;
}

bool		AForm::getIsSigned(void) const{
	return this->_is_signed;
}
/*
void		AForm::setName(std::string name){

	this->_name = name;
}


void		AForm::setGrade(int grade){

	if (grade < 1)
		throw GradeTooLowException();
	else if (grade > 150)
		throw GradeTooHighException();
	else 
		this->_grade = grade;
}
*/

void		AForm::beSigned(Bureaucrat &bureaucrat){
	
	if (bureaucrat.getGrade() > this->getGradeToSign())
		throw GradeTooLowException();
	else
		this->_is_signed = true;
}

void		AForm::execute(Bureaucrat const &executor){

	if (this->_grade_to_exec < executor.getGrade())
		throw AForm::GradeTooLowException();
	else if (this->getIsSigned() == false)
		throw AForm::FormIsNotSigned();
	this->beExecuted();
 

}
