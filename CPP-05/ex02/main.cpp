#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"


int	main()

{

	ShrubberyCreationForm	zazou("zazou");
	PresidentialPardonForm	papou("papou");
	RobotomyRequestForm		papah("papah");
	Bureaucrat				Patrick("Patrick", 1);

	try{
			Patrick.signForm(zazou);
			std::cout << zazou;
			Patrick.executeForm(zazou);
	}
	catch(std::exception &e){
			std::cout <<  e.what() << std::endl;
	}
	try{
			Patrick.signForm(papou);
			std::cout << papou;
			Patrick.executeForm(papou);
	}
	catch(std::exception &e){
			std::cout <<  e.what() << std::endl;
	}
	try{
			Patrick.signForm(papah);
			std::cout << papah;
			Patrick.executeForm(papah);
	}
	catch(std::exception &e){
			std::cout <<  e.what() << std::endl;
	}
}
