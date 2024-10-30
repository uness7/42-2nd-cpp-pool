# include "AForm.hpp"
# include "Bureaucrat.hpp"

/* Default constructor */
AForm::AForm(void) 
	: 
		_name("unnamed"), 
		_gradeToSign(HIGHEST_GRADE), 
        	_gradeToExecute(HIGHEST_GRADE), 
		_isSigned(false) {}

/* Param. constructor */
AForm::AForm(const std::string &name, const int gradeSign, const int gradeExecute)
	:
		_name(name),
		_gradeToSign(gradeSign),
		_gradeToExecute(gradeExecute)
{
	if (gradeSign < 1 || gradeExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeSign > 150 || gradeExecute > 150)
		throw AForm::GradeTooLowException();
	this->_isSigned = false;
}

/* Destructor */
AForm::~AForm(void) {}

/* Copy constructor */
AForm::AForm(const AForm &other)
	: 
		_name(other._name), 
		_gradeToSign(other._gradeToSign), 
		_gradeToExecute(other._gradeToExecute), 
		_isSigned(other._isSigned)
{
}

/* Ass. overloaded oeprator */
AForm	&AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return *this;
}

// Getters
std::string	AForm::getName(void) const
{
	return this->_name;
}

int	AForm::getGradeToExecute(void) const
{
	return this->_gradeToExecute;
}

int	AForm::getGradeToSign(void) const
{
	return this->_gradeToSign;
}

bool	AForm::getIsSigned(void) const
{
	return this->_isSigned;
}

void    AForm::beSigned(const Bureaucrat &bur)
{
	if (bur.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	this->_isSigned = true;
}

// Exceptions
const char*	AForm::GradeTooHighException::what() const throw()
{
	return "The Bureaucrat's grade is unfortunately too higher than the form's to-sign grade!";
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return "The Bureaucrat's grade is unfortunately lower than the form's to-sign grade!";
}

const char*	AForm::FormNotSignedException::what() const throw()
{
	return "The form is not signed";
}

/* Insertion overloaded operator */
std::ostream &operator<<(std::ostream &o, const AForm &form)
{
        o << form.getName() 
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
