
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): _target("Unspecified"), AForm("ShrubberyCreationForm", 145, 137)
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137){

	this->_target = target;
}

void	ShrubberyCreationForm::beExecuted(void){

	std::string	string;
	string = this->_target + "Shrubbery";
	std::ofstream	NewFile;

	NewFile.open(string.c_str());
	if (!NewFile.is_open())
		throw  FileNotOpenException();
	
	NewFile << "             .        +          .      .          .\n\
     .            _        .                    .\n\
  ,              /;-._,-.____        ,-----.__\n\
 ((        .    (_:#::_.:::. `-._   /:, /-._, `._,\n\
  `                 \\   _|`\"=:_::.`.);  \\ __/ /\n\
                      ,    `./  \\:. `.   )==-'  .\n\
    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           .\n\
.           \\/:/`-' , ,\\ '` ` `   ): , /_  -o\n\
       .    /:+- - + +- : :- + + -:'  /(o-) \\)     .\n\
  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7\n\
   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/\n\
              \\:  `  X` _| _,\\/'   .-'\n\
.               \":._:`\\____  /:'  /      .           .\n\
                    \\::.  :\\/:'  /              +\n\
   .                 `.:.  /:'  }      .\n\
           .           ):_(:;   \\           .\n\
                      /:. _/ ,  |\n\
                   . (|::.     ,`                  .\n\
     .                |::.    {\\  \n\
                      |::.\\  \\ `.\n\
                      |:::(\\    |\n\
              O       |:::/{ }  |                  (o\n\
               )  ___/#\\::`/ (O \"==._____   O, (O  /`\n\
          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~\n\
dew   ~~~~~~~~~~~~~~~~~~~~~~~\\\\W~~~~~~~~~~~~\\|/~~ " << std::endl;

	NewFile.close();
	return;
}



ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &type) : AForm(type){
	
	*this = type;
}



ShrubberyCreationForm::~ShrubberyCreationForm(void){

//	std::cout << "ShrubberyCreationForm default destructor called" << std::endl;
}

std::string	ShrubberyCreationForm::getTarget(void){
	return (this->_target);
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &type){

	this->_target = type.getIsSigned();
	return (*this);
}
