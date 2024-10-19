# include "Bureaucrat.hpp"
# include "Form.hpp"

Bureaucrat::Bureaucrat(void) : _name("unnamed"), _grade(LOWEST_GRADE) {}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat 	&Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat(void) {}

std::string	Bureaucrat::getName(void) const
{
	return this->_name;
}

int 	Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

void	Bureaucrat::incrementGrade(void)
{
	if (getGrade() - 1 <= HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	this->_grade -= 1;
}

void	Bureaucrat::decrementGrade(void)
{
	if (getGrade() + 1 > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->_grade += 1;
}

void	Bureaucrat::signForm(const Form &form) const
{
	if (form.getIsSigned() == true)
	{
		std::cout << this->getName() << " signed " << form.getName() << "." << std::endl;
	}
	else
	{
		std::cout << this->getName() << " could not sign " << form.getName();
		std::cout << " because he doesn't have qualifying grade" << std::endl;
	}
}

// Exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high! Must be at least 1.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low! Must be at most 150.";
}

// output overloaded operator
std::ostream	&operator <<(std::ostream &o, const Bureaucrat &bur)
{
	o << bur.getName() << ", bureaucrat grade " << bur.getGrade() << ".";
	return o;
}
