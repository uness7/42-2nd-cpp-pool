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


AForm*	Intern::makeForm(std::string name, std::string target)
{
	int		i;
	std::string	chosen;
	t_form	data[] =
	{
		{ "presidential pardon", new PresidentialPardonForm(target) },
		{ "robotomy request", new RobotomyRequestForm(target) },
		{ "shrubbery creation", new ShrubberyCreationForm(target) },
		{ "", NULL }
	};
	chosen = name;
	i = 0;
	while (data[i].form != NULL)
	{
		if (data[i].type == chosen)
		{
			std::cout << "Intern creates " << chosen << std::endl;
			return data[i].form;
		}
		i++;
	}
	throw  UnknownFormException();
	return (NULL);
}
