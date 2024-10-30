# include "Bureaucrat.hpp"
# include "Form.hpp"

int     main(void)
{
	try {
		try {
			Bureaucrat  obj("waizi", 8);
			Form    form("A4", 7, 7);

			std::cout << obj << std::endl;
			std::cout << form << std::endl;
			obj.signForm(form);
			std::cout << form << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}

		try {
			Bureaucrat  obj("Shady", 1);
			Form    form("A4", 2, 7);

			std::cout << obj << std::endl;
			std::cout << form << std::endl;
			obj.signForm(form);
			std::cout << form << std::endl;

		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}

	} catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
