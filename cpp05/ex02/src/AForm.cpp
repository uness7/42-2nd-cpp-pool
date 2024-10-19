# include "../inc/Form.hpp"
# include "../inc/Bureaucrat.hpp"

Form::Form() 
	: 
		_name("unnamed"), 
		_gradeToSign(HIGHEST_GRADE), 
        	_gradeToExecute(HIGHEST_GRADE), 
		_isSigned(false) {}

Form::Form(const std::string &name, const int gradeSign, const int gradeExecute)
	:
		_name(name),
		_gradeToSign(gradeSign),
		_gradeToExecute(gradeExecute)
{
	if (gradeSign < 1 || gradeExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeSign > 150 || gradeExecute > 150)
		throw Form::GradeTooLowException();
	this->_isSigned = false;
}

Form::~Form(void) {}

Form::Form(const Form &other)
	: 
		_name(other._name), 
		_gradeToSign(other._gradeToSign), 
		_gradeToExecute(other._gradeToExecute), 
		_isSigned(other._isSigned)
{
}

Form	&Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return *this;
}

// Getters
std::string	Form::getName(void) const
{
	return this->_name;
}

int	Form::getGradeToExecute(void) const
{
	return this->_gradeToExecute;
}

int	Form::getGradeToSign(void) const
{
	return this->_gradeToSign;
}

bool	Form::getIsSigned(void) const
{
	return this->_isSigned;
}

// Exceptions
const char*	Form::GradeTooHighException::what() const throw()
{
	return "The Bureaucrat's grade is unfortunately too higher than the form's to-sign grade!";
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return "The Bureaucrat's grade is unfortunately lower than the form's to-sign grade!";
}

std::ostream &operator<<(std::ostream &o, const Form &form)
{
        o << form.getName() 
		<< ", grade for signing: " 
		<< form.getGradeToSign() 
		<< ", grade for executing: " ;
        o << form.getGradeToExecute() << "." << std::endl;
        return o;
}
