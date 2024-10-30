#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>
# include <string>

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

class AForm;

class Bureaucrat
{
	private:
		const std::string   _name;
		int 				_grade;
		
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &src);
		~Bureaucrat(void);
		Bureaucrat	&operator =(const Bureaucrat &src);

		std::string	getName(void) const;
		int 		getGrade(void) const;

		void		incrementGrade(void);
		void		decrementGrade(void);

		void		signForm(AForm &form) const;
		void 		executeForm(AForm const & form);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual  const char* what() const throw();
		};
};

std::ostream	&operator <<(std::ostream &o, const Bureaucrat &bur);

#endif
