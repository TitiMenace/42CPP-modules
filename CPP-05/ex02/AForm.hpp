
#pragma once

#include <string>
#include <iostream>
#include <exception>


class Bureaucrat;

class	AForm{
		
	private:

		const std::string	_name;
		bool			_is_signed;
		const	int		_grade_to_sign;
		const	int		_grade_to_exec;

		virtual void	beExecuted(void) = 0;


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
		
		class	FormIsNotSigned : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return("Error: Form: FormIsNotSigned: Can't execute form because it is not signed !");
				}		
		};
		
		AForm(void);
		AForm(std::string name, const int gradeToSign, const int gradeToExec);
		AForm(AForm &type);
		virtual ~AForm(void) = 0;
		AForm &operator=(const AForm &type);

		std::string 	getName(void) const;
		int		getGradeToSign(void) const;
		int		getGradeToExec(void) const;
		bool		getIsSigned(void) const;
		void	execute(Bureaucrat const &executor);

		void		beSigned(Bureaucrat &bureaucrat);


	//	void		setName(std::string name);
	//	void		setGrade(int grade);

	};

std::ostream &operator<<(std::ostream &stream, const AForm &form);
