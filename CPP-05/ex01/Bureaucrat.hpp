#pragma once

#include <string>
#include <iostream>
#include <exception>

class Form;

class	Bureaucrat{
		
	public:

		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return("Error: Bureaucrat: GradeTooHigh: Grade is in between 1 and 150 included !");
				}
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return("Error: Bureaucrat: GradeTooLow: Grade is in between 1 and 150 included !");
				}
		};
		
		Bureaucrat(void);
		~Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &type);
		Bureaucrat &operator=(const Bureaucrat &type);

		std::string 	getName(void) const;
		int		getGrade(void) const;

	//	void		setName(std::string name);
		void		setGrade(int grade);

		void		incrGrade(void);
		void		decrGrade(void);
		void		signForm(Form &form);


	private:

		const std::string	_name;
		int			_grade;
};

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &bureaucrat);
