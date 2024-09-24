# include "../inc/Bureaucrat.hpp"

int     main()
{
	Bureaucrat	obj("Waizi", 150);
	std::cout << obj << std::endl;

	try {
		// grade after decrementing would become 151 which is too low
		// thus, exception should take place
		obj.decrementGrade(); // grade = 151
		std::cout << obj << std::endl;
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl;

	Bureaucrat	obj1("John Doe", 1);
	std::cout << obj1 << std::endl;

	try {
		obj1.incrementGrade();
		std::cout << obj1 << std::endl;
	} catch(Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	

	std::cout << std::endl;

	Bureaucrat	obj2("Jack Doe", 100);

	try {
		std::cout << obj2 << std::endl;
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
