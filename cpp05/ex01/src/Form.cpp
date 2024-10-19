# include "Form.hpp"
# include "Bureaucrat.hpp"

Form::Form(
		const std::string &name, 
		const int gradeSign, 
		const int gradeExecute)
	: 
		_name(name),
		_gradeToSign(gradeSign),
		_gradeToExecute(gradeExecute),
		_isSigned(false)
{
	if (gradeSign < 1 || gradeExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeSign > 150 || gradeExecute > 150)
		throw Form::GradeTooLowException();
}

Form::~Form(void) {}

Form::Form(const Form &other) : _name(other._name), _gradeToSign(other._gradeToSign), 
	_gradeToExecute(other._gradeToExecute), _isSigned(other._isSigned) {}

Form	&Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->_isSigned = other.getIsSigned();
	}
	return *this;
}

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

void	Form::beSigned(const Bureaucrat &bur)
{
	if (bur.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	this->_isSigned = true;
}

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
        o << form.getName() << ", grade for signing: " << form.getGradeToSign() << ", grade for executing: " ;
        o << form.getGradeToExecute() << "." << std::endl;
        return o;
}
