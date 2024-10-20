# include "AForm.hpp"
# include "Intern.hpp"
# include "Bureaucrat.hpp"

int	main(void)
{
	{
		try {
			Intern	someRandomIntern;
			AForm* 	rrf;
			rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
			std::cout << *rrf << std::endl;

			rrf = someRandomIntern.makeForm("robotomy request", "28B");
			std::cout << *rrf << std::endl;
			std::cout << std::endl;

			rrf = someRandomIntern.makeForm("presidential pardon", "28A");
			std::cout << *rrf << std::endl;
			std::cout << std::endl;

			rrf = someRandomIntern.makeForm("blah", "28A");
			std::cout << *rrf << std::endl;
			std::cout << std::endl;

			delete rrf;

		} catch (Intern::UnknownFormException & e) {
			std::cout << e.what() << std::endl;
		}
	}

	return (0);
}
