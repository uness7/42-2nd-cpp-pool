#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>
# include <string>

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

class Form;

class Bureaucrat
{
	private:
		const std::string   	_name;
		int 			_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat(void);

		std::string	getName(void) const;
		int 		getGrade(void) const;

		void		incrementGrade(void);
		void		decrementGrade(void);
		void		signForm(Form &form);

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
};

std::ostream	&operator <<(std::ostream &o, const Bureaucrat &bur);

#endif
