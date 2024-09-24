# ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class Form 
{
	private:
		const std::string	_name;
		int 			_gradeToSign;
		int 			_gradeToExecute;
		bool			_isSigned;

	public:
		Form();
		Form(const std::string &name, int gradeToSign, int gradeToExecute);
		Form(const Form &src);
        ~Form();
		Form &operator =(const Form &src);

		// Getters
		std::string	getName(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExecute(void) const;
		bool		getIsSigned(void) const;

		// Exceptions
		class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
		public:
			virtual  const char* what() const throw();

		};

		// Member Functions
		void	beSigned(const Bureaucrat &bur);

};

std::ostream	&operator <<(std::ostream &o, const Form &bur);

# endif
