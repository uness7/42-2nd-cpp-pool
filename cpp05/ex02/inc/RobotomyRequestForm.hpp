# ifndef ROBOTOMY_REQUEST_FORM_H
# define ROBOTOMY_REQUEST_FORM_H

# include <iostream>
# include <string>
# include <cstdlib>
# include "AForm.hpp"

class Bureaucrat;
class AForm;

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm( std::string target) ;
		RobotomyRequestForm( const RobotomyRequestForm& other) ;
		RobotomyRequestForm &operator=( const RobotomyRequestForm& other) ;
		~RobotomyRequestForm(void);

		void	execute( const Bureaucrat& executor ) const;
};

# endif
