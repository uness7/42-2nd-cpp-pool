# include "Bureaucrat.hpp"

/* Default constructor */
Bureaucrat::Bureaucrat(void)
	:
		_name("unnamed"),
		_grade(LOWEST_GRADE) {}

/* Parameterized constructor */
Bureaucrat::Bureaucrat(const Bureaucrat &src)
	:
		_name(src._name),
		_grade(src._grade) {}

/* Copy constructor */
Bureaucrat::Bureaucrat(const std::string &name, int grade)
	:
	       _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

/* Assignment operator */
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
    if (this != &src)
    {
        this->_grade = src._grade;
    }
    return *this;
}

/* Getters */
std::string Bureaucrat::getName() const
{
	return this->_name;
}

int 	Bureaucrat::getGrade() const
{
	return this->_grade;
}

/* Member Methods */
void	Bureaucrat::incrementGrade()
{
	if (getGrade() - 1 <= HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	this->_grade -= 1;
}

void	Bureaucrat::decrementGrade()
{
	if (getGrade() + 1 > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->_grade += 1;
}

/* Exceptions Definitions */
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high! Must be at least 1.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low! Must be at most 150.";
}

/* Output stream overloaded operator  */
std::ostream	&operator <<(std::ostream &o, const Bureaucrat &bur)
{
	o << bur.getName() << ", bureaucrat grade " << bur.getGrade() << ".";
	return o;
}
