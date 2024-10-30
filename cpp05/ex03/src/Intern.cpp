# include "Intern.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

/* Default constructor */
Intern::Intern( void ) {
	const std::string formNames[3] = {
		"shrubbery creation", 
		"robotomy request", 
		"presidential pardon"
	};

	_makeForm[0] = &Intern::makeShrubberyCreationForm;
	_makeForm[1] = &Intern::makePresidentialPardonForm;
	_makeForm[2] = &Intern::makeRobotomyRequestForm;
}


/* Destructor */
Intern::~Intern( void ) {}

/* Copy constructor */
Intern::Intern( const Intern & other )
{
	*this = other;
}

/* Assignment overloaded operator */
Intern &Intern::operator=( const Intern & other )
{
	(void)other;
	return *this;
}

/* Exceptions */
const char*     Intern::UnknownFormException::what() const throw() {
	return "Form is unknown\n";
}

/* Member functions */
AForm*	Intern::makeShrubberyCreationForm(const std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm*	Intern::makePresidentialPardonForm(const std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm*	Intern::makeRobotomyRequestForm(const std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm*	Intern::makeForm( std::string name, std::string target )
{
	int	i = 0;
	while (i < 3)
	{
		if (_formNames[i] == name)
		{
			std::cout << "Intern creates " << std::endl;
			return ((this->*_makeForm[i])(target));
		}
		i++;
	}
	throw UnknownFormException();
	return NULL;
}
