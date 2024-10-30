# include "PresidentialPardonForm.hpp"

/* Default constructor */
PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm("unnamded", 25, 5), _target("nobody") {}

/* Param. constructor */
PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("president", 25, 5), _target(target) {}

/* Destructor */
PresidentialPardonForm::~PresidentialPardonForm(void) {}

/* Copy constructor */
PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & other)
	: AForm(other), _target(other._target) {}

/* Assignment overloaded operator */
PresidentialPardonForm &PresidentialPardonForm::operator=( const PresidentialPardonForm & other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

/* Member functions */
void	PresidentialPardonForm::execute( const Bureaucrat & executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooHighException();
	if (this->getIsSigned() == false)
		throw FormNotSignedException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
