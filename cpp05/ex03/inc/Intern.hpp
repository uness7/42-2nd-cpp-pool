# ifndef INTERN_H
# define INTERN_H

# include <iostream>
# include <string>
# include "AForm.hpp"

class Intern
{
private:
	typedef struct s_form
	{
		std::string	type;
		AForm		*form;
	}	t_form;
public:
	Intern( void );
	~Intern( void );
	Intern( const Intern & other );
	Intern &operator=( const Intern & other );

	class UnknownFormException : public std::exception {
		public:
			virtual  const char* what() const throw();
	};

	AForm*	makeForm(std::string name, std::string target);
};

# endif
