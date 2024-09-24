#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>
# include <string>

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

class Form;

class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat	&operator =(const Bureaucrat &src);

		/* Getters */
		std::string	getName() const;
		int 		getGrade() const;

		/* Member Functions */
		void		incrementGrade();
		void		decrementGrade();
		void		signForm(const Form &form) const;

		/* Nested Exception Classes */
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual  const char* what() const throw();

		};

	private:
		const std::string   _name;
		int 				_grade;
};

std::ostream	&operator <<(std::ostream &o, const Bureaucrat &bur);

#endif
