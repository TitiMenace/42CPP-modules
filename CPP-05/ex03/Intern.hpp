
#pragma once

#include <string>
#include <iostream>
#include <exception>

class AForm;

class	Intern{
		
	public:

		Intern(void);
		~Intern(void);
		Intern(const Intern &type);
		Intern &operator=(const Intern &type);


		class	FormTypeNotFound : public	std::exception {

			public :
						virtual const char	*what() const throw()
						{
							return ("Error: Form type doesn't match");
						}
		};
		AForm	*makeForm(std::string form, std::string target) const;

	private:
};

