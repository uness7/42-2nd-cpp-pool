# ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class AForm 
{
	private:
		const std::string	_name;
		const int 		_gradeToSign;
		const int 		_gradeToExecute;
		bool			_isSigned;

	public:
		AForm(void);
		AForm(const std::string &name, const int gradeToSign, const int gradeToExecute);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		~AForm(void);

		std::string	getName(void) const;
		int		getGradeToSign(void) const;
		int		getGradeToExecute(void) const;
		bool		getIsSigned(void) const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual  const char* what() const throw();
		};
		void	beSigned(const Bureaucrat &bur) = 0;
};

std::ostream &operator<<(std::ostream &o, const AForm &bur);

# endif
