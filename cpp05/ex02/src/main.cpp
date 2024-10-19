# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"

int     main(void)
{
	ShrubberyCreationForm shrubbery("MGK"); // 145, 137
	Bureaucrat alice("Alice", 1);

	alice.signForm(shrubbery);
	alice.executeForm(shrubbery);
}

