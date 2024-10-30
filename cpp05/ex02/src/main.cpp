# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

int     main(void)
{
	try {
		ShrubberyCreationForm shrubbery("MGK");
		RobotomyRequestForm robotomy("NGOLO");
		PresidentialPardonForm president("putin");

		Bureaucrat alice("Alice", 1);
		Bureaucrat mark("Mark", 3);
		Bureaucrat danas("Danas", 2);

		alice.signForm(shrubbery);
		alice.executeForm(shrubbery);

		std::cout << std::endl;

		mark.signForm(robotomy);
		mark.executeForm(robotomy);

		std::cout << std::endl;

		danas.signForm(president);
		danas.executeForm(president);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
