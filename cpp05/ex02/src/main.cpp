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

		shrubbery.beSigned(alice);
		//robotomy.beSigned(mark);
		president.beSigned(danas);

		alice.signForm(shrubbery);
		alice.executeForm(shrubbery);

		std::cout << std::endl;

		mark.signForm(robotomy);
		mark.executeForm(robotomy);

		std::cout << std::endl;

		danas.signForm(president);
		danas.executeForm(president);
	}
	catch (AForm::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (AForm::FormNotSignedException &e)
	{
		std::cout << e.what() << std::endl;
	}
}
