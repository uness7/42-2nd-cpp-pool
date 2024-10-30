# include "RobotomyRequestForm.hpp"

/* Default constructor */
RobotomyRequestForm::RobotomyRequestForm(void) 
	: AForm("unnamed", 72, 45), _target("nobody") {srand(time(0));}

/* Param. constructor */
RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("robotomy", 72, 45), _target(target) {srand(time(0));}

/* Copy constructor */
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), _target(other._target) {}

/* Assignment overloaded oepartor */
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

/* Destructor */
RobotomyRequestForm::~RobotomyRequestForm(void) {}

/* Member functions */
void	RobotomyRequestForm::execute( const Bureaucrat& executor) const
{
	if (this->getIsSigned() == false)
		throw FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	std::cout << "BRRrrrrrrrr........................." << std::endl;
	if (rand() % 2 == 0)
		std::cout << this->_target << " has been robotomized" << std::endl;
	else
		std::cout << this->_target << " has failed to be robotomized" << std::endl;
}
