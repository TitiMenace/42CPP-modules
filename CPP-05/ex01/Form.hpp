
#pragma once

#include <string>
#include <iostream>
#include <exception>


class Bureaucrat;

class	Form{
		
	private:

		const std::string	_name;
		bool			_is_signed;
		const	int		_grade_to_sign;
		const	int		_grade_to_exec;


	public:

		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return("Error: Form: GradeTooHigh: Grade is in between 1 and 150 included !");
				}
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return("Error: Form: GradeTooLow: Grade is in between 1 and 150 included !");
				}
		};
		
		Form(void);
		Form(std::string name, const int gradeToSign, const int gradeToExec);
		Form(Form &type);
		~Form(void);
		Form &operator=(const Form &type);

		std::string 	getName(void) const;
		int		getGradeToSign(void) const;
		int		getGradeToExec(void) const;
		bool		getIsSigned(void) const;

		void		beSigned(Bureaucrat &bureaucrat);


	//	void		setName(std::string name);
	//	void		setGrade(int grade);

	};

std::ostream &operator<<(std::ostream &stream, const Form &form);
