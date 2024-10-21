# include "Intern.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

Intern::Intern( void ) {}

Intern::~Intern( void ) {}

Intern::Intern( const Intern & other )
{
	*this = other;
}

Intern &Intern::operator=( const Intern & other )
{
	(void)other;
	return *this;
}

const char*     Intern::UnknownFormException::what() const throw() {
	return "Form is unknown";
}

AForm*	Intern::makeForm( std::string name, std::string target )
{
	t_form  data[] =
        {
                { "presidential pardon", new PresidentialPardonForm(target) },
                { "robotomy request", new RobotomyRequestForm(target) },
                { "shrubbery creation", new ShrubberyCreationForm(target) },
                { "", NULL }
        };
	AForm	*result = NULL;

	int	i;
	for (i = 0 ; data[i].form != NULL; i++)
	{
		if (data[i].type == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			result = data[i].form;
			break ;
		}
	}
	// Delete all forms except the matching one
	for (int j = 0; data[j].form != NULL; j++)
	{
		if (data[j].form != result)  // Don't delete the one we're returning
			delete data[j].form;
	}

	if (result == NULL)
		throw UnknownFormException();

	std::cout << "Intern creates " << name << std::endl;
	return result;
}
