# include "Form.hpp"
# include "Bureaucrat.hpp"

/* Default constructor */
Form::Form(void)
	: _name("unnamed"), _gradeToSign(LOWEST_GRADE), _gradeToExecute(LOWEST_GRADE), _isSigned(false) {}

/* Param. constructor */
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

/* Copy Constructor */
Form::Form(const Form &other) 
	: _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute), _isSigned(other._isSigned) {}

/* Ass. overloaded operator */
Form	&Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->_isSigned = other.getIsSigned();
	}
	return *this;
}

/* Destructor constructor */
Form::~Form(void) {}

/* Getters */
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

/* Member functions */
void	Form::beSigned(const Bureaucrat &bur)
{
	if (bur.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	this->_isSigned = true;
}

/* Exceptions */
const char*	Form::GradeTooHighException::what() const throw()
{
    return "The Bureaucrat's grade is unfortunately too lower than the form's to-sign grade!\n";
}

const char*	Form::GradeTooLowException::what() const throw()
{
    return "The Bureaucrat's grade is unfortunately higher than the form's to-sign grade!\n";
}

/* Insertion overloaded operator */
std::ostream &operator<<(std::ostream &o, const Form &form)
{
        o 
		<< form.getName() 
		<< ", grade for signing: " 
		<< form.getGradeToSign() 
		<< ", grade for executing: " 
		<< form.getGradeToExecute()  
		<< ", is signed: "
		<< (form.getIsSigned() ? "true" : "false")
		<< "."
		<< std::endl;
        return o;
}
