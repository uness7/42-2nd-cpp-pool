# include "ShrubberyCreationForm.hpp"

/* Default constructor */
ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("unnamed", 145, 137), _target("nobody") {}

/* Param. constructor */
ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("Shrubbery", 145, 137), _target(target) {}

/* Copy constructor */
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target) {} 

/* Assignment overloaded operator */
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

/* Destructor */
ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

/* Member functions */
void	ShrubberyCreationForm::execute(const Bureaucrat & executor) const
{
	if (this->getIsSigned() == false)
		throw FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	std::ofstream file((this->_target + "_shrubbery").c_str());
	if (!file.is_open())
		std::cerr << "Error: file can't be opened" << std::endl;

	file << "       *            *       \n";
	file << "      ***          ***      \n";
	file << "     *****        *****     \n";
	file << "    *******      *******    \n";
	file << "   *********    *********   \n";
	file << "  ***********  ***********  \n";
	file << " ************************** \n";
	file << "      |||          |||      \n";
	file << "      |||          |||      \n";
	file.close();
}


