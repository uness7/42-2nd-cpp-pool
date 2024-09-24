# include "../inc/Form.hpp"
# include "../inc/Bureaucrat.hpp"

Form::Form() 
	: 
		_name("unnamed"), 
		_gradeToSign(LOWEST_GRADE), 
        _gradeToExecute(LOWEST_GRADE), 
		_isSigned(false)
{
	// Default Constructor
}

Form::Form(const std::string &name, int gradeSign, int gradeExecute) : _name(name)
{
    if (gradeSign < 1 || gradeExecute < 1)
        throw Form::GradeTooHighException();
    else if (gradeSign > 150 || gradeExecute > 150)
        throw Form::GradeTooLowException();
    this->_gradeToSign = gradeSign;
    this->_gradeToExecute = gradeExecute;
    this->_isSigned = false;
}

Form::~Form() {
	// Destructor
}

Form::Form(const Form &src)
	: 
		_name(src._name), 
		_gradeToSign(src._gradeToSign), 
		_gradeToExecute(src._gradeToExecute), 
		_isSigned(src._isSigned)
{
	// Copy constructor
}

Form	&Form::operator=(const Form &src) {
	if (this != &src) {
		//this->_name = src._name; // bc name is has a const qualifier
		this->_gradeToSign = src._gradeToSign;
		this->_gradeToExecute = src._gradeToExecute;
		this->_isSigned = src._isSigned;
	}
	return *this;
}

// Getter 
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
	if (bur.getGrade() <= this->_gradeToSign)
		this->_isSigned = true;
    else
        throw Form::GradeTooLowException();
}

// Exceptions
const char* Form::GradeTooHighException::what() const throw() {
    return "The Bureaucrat's grade is unfortunately too higher than the form's to-sign grade!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "The Bureaucrat's grade is unfortunately lower than the form's to-sign grade!";
}

std::ostream    &operator <<(std::ostream &o, const Form &form)
{
        o << form.getName() << ", grade for signing: " << form.getGradeToSign() << ", grade for executing: " ;
        o << form.getGradeToExecute() << "." << std::endl;
        return o;
}
