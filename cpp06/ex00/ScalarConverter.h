# ifndef SCALAR_CONVERTER_H
# define SCALAR_CONVERTER_H

# include <iostream>
# include <string>
# include <climits>
# include <iomanip>
# include <algorithm> 



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
bool	isSpecial(std::string const value);

void	convertChar(std::string const value);
void	convertDouble(std::string const value);
void	convertInt(std::string const value);
void	convertFloat(std::string const value);
void	convertNan(std::string const value);

# endif
