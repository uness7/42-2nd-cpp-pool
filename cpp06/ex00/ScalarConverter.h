# ifndef SCALAR_CONVERTER_H
# define SCALAR_CONVERTER_H

# include <iostream>
# include <stdlib.h>
# include <string>


class ScalarConverter {
	private:
		ScalarConverter(void);

	public:
		ScalarConverter(ScalarConverter const &other);
		ScalarConverter &operator =(ScalarConverter const &other);
		~ScalarConverter(void);

		static void	convert(std::string const value);
};


/* Non-member functions */
bool	isChar(std::string const value);
bool	isInt(std::string const value);
bool	isDouble(std::string const value);
bool	isFloat(std::string const value);


# endif
