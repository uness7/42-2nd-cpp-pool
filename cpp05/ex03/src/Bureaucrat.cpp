# include "Bureaucrat.hpp"
# include "AForm.hpp"

/* Default constructor */
Bureaucrat::Bureaucrat(void) : _name("unnamed"), _grade(LOWEST_GRADE) {}

/* Param. constructor */
Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade) {}

/* Copy constructor */
Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

/* Assignment overloaded operator */
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
    if (this != &src) {
        this->_grade = src._grade;
    }
    return *this;
}

/* Destructor */
Bureaucrat::~Bureaucrat(void) {}

/* Getters */
std::string Bureaucrat::getName(void) const
{
	return this->_name;
}

int 	Bureaucrat::getGrade(void) const {
	return this->_grade;
}

/* Member functions */
void	Bureaucrat::incrementGrade(void)
{
	if (getGrade() - 1 < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	this->_grade -= 1;
}

void	Bureaucrat::decrementGrade(void)
{
	if (getGrade() + 1 > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->_grade += 1;
}

void	Bureaucrat::signForm(AForm &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << "." << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout 
			<< this->getName() << " could not sign " << form.getName()
			<< " because he doesn't have qualifying grade" << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try {
		form.execute(*this);
		std::cout
			<< this->getName() << " executed "
			<< form.getName() << " " << std::endl;
	} catch(const std::exception& e) {
		std::cout
			<< this->getName() << " couldn't execute " << form.getName()
			<< " because " << e.what() << std::endl;
	}   
}

/* Exceptions */
const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high! Must be at least 1.\n";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low! Must be at most 150.\n";
}

/* Insertion overloaded operator */
std::ostream	&operator <<(std::ostream &o, const Bureaucrat &bur)
{
	o << bur.getName() << ", bureaucrat grade " << bur.getGrade() << "." << std::endl;
	return o;
}
