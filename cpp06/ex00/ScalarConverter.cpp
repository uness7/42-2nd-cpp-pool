# include "ScalarConverter.h"

ScalarConverter::ScalarConverter(void) {}
ScalarConverter::~ScalarConverter(void) {}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
	(void)other;
}

ScalarConverter&	ScalarConverter::operator=(ScalarConverter const &other)
{
	(void)other;
	return (*this);
}

/*
 * - for this value string to be considered as a char, here are the conditions:
 *   1. length = 1
 * */
bool	isChar(std::string const value)
{
	//
	return (false);
}

/* Member functions */
void	ScalarConverter::convert(std::string const value)
{
}


