# ifndef SHRUBBERY_CREATION_FORM_H
# define SHRUBBERY_CREATION_FORM_H

# include <iostream>
# include <string>
# include "AForm.hpp"

class Bureaucrat;
class AForm;

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm( std::string target );
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm( const ShrubberyCreationForm& other );
		ShrubberyCreationForm &operator=( const ShrubberyCreationForm& other );

		void    execute(const Bureaucrat & executor) const;
};

# endif

