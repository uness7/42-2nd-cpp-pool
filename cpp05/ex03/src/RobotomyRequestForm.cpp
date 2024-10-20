# include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) 
	: AForm("unnamed", 72, 45), _target("nobody") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("robotomy", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), _target(other._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

void	RobotomyRequestForm::execute( const Bureaucrat& executor) const
{
	if (this->getIsSigned() == false)
		throw FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooHighException();
	std::cout << "BRRrrrrrrrr........................." << std::endl;
	srand(time(0));
	if (rand() % 2 == 0)
		std::cout << this->_target << " has been robotomized" << std::endl;
	else
		std::cout << this->_target << " has failed to be robotomized" << std::endl;
}
