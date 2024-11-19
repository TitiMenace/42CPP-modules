#include "Bureaucrat.hpp"


int	main()
{
	try{
		Bureaucrat	Bureaucrat1("Zack", 1);
		std::cout << Bureaucrat1 << std::endl;
	} catch(std::exception &e){
		
		std::cout << e.what() << std::endl;
	}
	try{
		Bureaucrat	Bureaucrat2("Regis", 150);
		std::cout << Bureaucrat2 << std::endl;
	} catch(std::exception &e){
		
		std::cout << e.what() << std::endl;
	}
	try{
		Bureaucrat	Bureaucrat3("Lennon", 151);
		std::cout << Bureaucrat3 << std::endl;
	} catch(std::exception &e){
		
		std::cout << e.what() << std::endl;
	}
	try{
		Bureaucrat	Bureaucrat4("My man", -1);
		std::cout << Bureaucrat4 << std::endl;
	} catch(std::exception &e){
		
		std::cout << e.what() << std::endl;
	}
	try{
		Bureaucrat	Johnny("Johnny", 147);
		std::cout << Johnny << std::endl;
		Johnny.incrGrade();
		std::cout << Johnny << std::endl;
		Johnny.incrGrade();
		std::cout << Johnny << std::endl;
		Johnny.incrGrade();
		std::cout << Johnny << std::endl;
		Johnny.incrGrade();
		std::cout << Johnny << std::endl;
	} catch(std::exception &e){
		
		std::cout << e.what() << std::endl;
	}
	try{
		Bureaucrat	Sardou("Sardou", 4);
		std::cout << Sardou << std::endl;
		Sardou.decrGrade();
		std::cout << Sardou << std::endl;
		Sardou.decrGrade();
		std::cout << Sardou << std::endl;
		Sardou.decrGrade();
		std::cout << Sardou << std::endl;
		Sardou.decrGrade();
		std::cout << Sardou << std::endl;
	} catch(std::exception &e){
		
		std::cout << e.what() << std::endl;
	}
}
