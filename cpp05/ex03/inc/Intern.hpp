# ifndef INTERN_H
# define INTERN_H

# include <iostream>
# include <string>
# include "AForm.hpp"

/*
   typedef return_type (*functionPointerType)(params)
   FunctionPointerType functionPointerArray[arraySize];
*/

class Intern
{
	private:
		std::string _formNames[3];
		AForm*	(Intern::*_makeForm[3])(const std::string);

	public:
		Intern( void );
		~Intern( void );
		Intern( const Intern & other );
		Intern &operator=( const Intern & other );

		class UnknownFormException : public std::exception {
			public:
				virtual  const char* what() const throw();
		};

		AForm*		makeForm(std::string name, const std::string target);
		AForm*		makeShrubberyCreationForm(const std::string target);
		AForm*		makePresidentialPardonForm(const std::string target);
		AForm*		makeRobotomyRequestForm(const std::string target);
};

# endif
