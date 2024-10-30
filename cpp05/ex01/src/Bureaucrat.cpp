# include "Bureaucrat.hpp"
# include "Form.hpp"

/* Default constructor */
Bureaucrat::Bureaucrat(void)
	: _name("unnamed"), _grade(LOWEST_GRADE) {}

/* Param. constructor */
Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

/* Copy constructor */
Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {}


/* Assignmenet operator */
Bureaucrat 	&Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return *this;
}

/* Destructor */
Bureaucrat::~Bureaucrat(void) {}

/* Getters */
std::string	Bureaucrat::getName(void) const
{
	return this->_name;
}

int 	Bureaucrat::getGrade(void) const
{
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

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << "." << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << this->getName() << " could not sign " 
			<< form.getName()
		 	<< " because he doesn't have qualifying grade" << std::endl;
	}
}

/* Exceptions */
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high! Must be at most 1.\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low! Must be at least 150.\n";
}

/* Insertion overloaded operator */
std::ostream	&operator <<(std::ostream &o, const Bureaucrat &bur)
{
	o << bur.getName() << ", bureaucrat grade " << bur.getGrade() << "." << std::endl;
	return o;
}
