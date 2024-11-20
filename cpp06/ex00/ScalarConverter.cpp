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

bool	isChar(std::string const value)
{
	if (value.size() == 1 && std::isdigit(value[0]) == false && std::isprint(value[0]) != 0)
		return (true);
	return (false);
}

bool	isSpecial(std::string const value)
{
	if (value == "-inf" || value == "+inf" || value == "-inff" || value == "+inff"
			|| value == "nan" || value == "nanf")
		return (true);
	return (false);
}

bool	isInt(std::string const value)
{
	long unsigned int	i = 0;
	while (std::isdigit(value[i]) == true)
		i++;
	if (i == value.length())
		return (true);
	return (false);
}

void	error(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << 0 << std::endl;
	std::cout << "float: " << 0 << std::endl;
	std::cout << "double: " << 0 << std::endl;
}

bool	isMinusInf(std::string const value)
{
	if (value == "-inf" || value == "-inff")
		return true;
	return false;
}

bool	isPlusInf(std::string const value)
{
	if (value == "+inf" || value == "+inff")
		return true;
	return false;
}

void	convertMinusInf(std::string const value)
{
	(void)value;
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << INT_MIN << std::endl;
	std::cout << "float: " << __FLT_MIN__ << std::endl;
	std::cout << "double: " << __DBL_MIN__ << std::endl;
}

void	convertPlusInf(std::string const value)
{
	(void)value;
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << INT_MAX << std::endl;
	std::cout << "float: " << __FLT_MAX__ << std::endl;
	std::cout << "double: " << __DBL_MAX__ << std::endl;
}

void	convertNan(std::string const value)
{
	(void)value;
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

void	convertInt(std::string const value)
{
	int	number = atoi(value.c_str());

	if (number < 0 || number > 127)
		std::cout << "char : impossible" << std::endl;
	else if (number < 32 || number == 127)
		std::cout << "char : non-displayable" << std::endl;
	else
		std::cout << "char : " << static_cast<char>(number) << std::endl;

	std::cout << "int: " << (number) << std::endl;
	std::cout << "float : " << std::fixed << std::setprecision(1) << static_cast<float>(number) << std::endl;
	std::cout << "double : " << std::fixed << std::setprecision(1) << static_cast<double>(number) << std::endl;
}

void	convertChar(std::string const value)
{
	std::cout << "char: " << static_cast<char>(value[0]) << std::endl;
	std::cout << "int: " << static_cast<int>(value[0]) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value[0]) << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value[0]) << std::endl;
}

bool	isDouble(std::string const value)
{
	(void)value;
	if (value.find('.') != std::string::npos)
	{
		long unsigned int	i = 0;
		while (std::isdigit(value[i]) || value[i] == '.')
			i++;
		if (i == value.length())
			return (true);
	}
	return false;
}

bool	isFloat(std::string const value)
{
	(void)value;
	if (value.length() - 1 == 'f')
	{
		long unsigned int	i = 0;
		while (i < value.length() - 1 && (std::isdigit(value[i]) || value[i] == '.'))
			i++;
		if (i == value.length())
			return (true);
	}
	return false;
}

void	convertDouble(std::string const value)
{
	double	number = atof(value.c_str());

	if (number < 0 || number > 127)
		std::cout << "char: impossible" << std::endl;
	else if (number < 32 || number == 127)
		std::cout << "char: non-displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(number) << std::endl;
	std::cout << "int: " << static_cast<int>(number) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(2) 
		<< static_cast<float>(number) << "f" << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(2) << number << std::endl;
}

void	convertFloat(std::string const value)
{
	float	number = atof(value.c_str());

	if (number < 0 || number > 127)
		std::cout << "char: impossible" << std::endl;
	else if (number < 32 || number == 127)
		std::cout << "char: non-displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(number) << std::endl;
	std::cout << "int: " << static_cast<int>(number) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(2) << number << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(2) << static_cast<double>(number) << std::endl;
}


void	ScalarConverter::convert(std::string const value)
{
	if (isChar(value) == true)
		convertChar(value);
	else if (isSpecial(value) == true)
	{
		if (isMinusInf(value) == true)
			convertMinusInf(value);
		else if (isPlusInf(value) == true)
			convertPlusInf(value);
		else 
			convertNan(value);
	}
	else if(isInt(value) == true)
		convertInt(value);
	else if (isDouble(value) == true)
		convertDouble(value);
	else if (isFloat(value) == true)
		convertFloat(value);
	else
		error();
}
