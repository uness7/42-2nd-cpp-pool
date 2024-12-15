#include "BitcoinExchange.hpp"
#include <limits>

BitcoinExchange::BitcoinExchange(void) {}
BitcoinExchange::~BitcoinExchange(void) {}
//BitcoinExchange::BitcoinExchange(BitcoinExchange const & src) { (void)src; }
//BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const & src) { (void)src; return *this; }

/* ------------------------------------------------------------ */

std::map<std::string, float>	BitcoinExchange::getBtc(void) const
{
	return this->_btc;
}

/* ------------------------------------------------------------ */

bool	isValidDate(std::string & date)
{
	size_t first = date.find_first_not_of(" \t");
	size_t last = date.find_last_not_of(" \t");
	if (first == std::string::npos || last == std::string::npos)
		return false;
	date = date.substr(first, last - first + 1);

	if (date.length() != 10) return false;
	if (date[4] != '-' || date[7] != '-') return false;

	int yy, mm, dd;
	std::stringstream ss(date);
	char dash1, dash2;

	if (!(ss >> yy >> dash1 >> mm >> dash2 >> dd))
		return false;

	if (yy < 1 || yy > 9999) return false;
	if (mm < 1 || mm > 12) return false;

	int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if ((yy % 4 == 0 && yy % 100 != 0) || (yy % 400 == 0))
		daysInMonth[2] = 29;

	if (dd < 1 || dd > daysInMonth[mm]) return false;

	return true;
}

bool	isValidValue(std::string& line)
{
	size_t start = line.find_first_not_of(" \t");
	size_t end = line.find_last_not_of(" \t");
	if (start == std::string::npos || end == std::string::npos) {
		return false;
	}
	line = line.substr(start, end - start + 1);

	std::istringstream iss(line);
	double value;
	if (!(iss >> value)) {
		return false;
	}

	std::string extra;
	if (iss >> extra) {
		return false;
	}

	if (value < 0 || value > 1000) {
		return false;
	}

	return true;
}

float	convertToFloat(const std::string& str)
{
	std::stringstream 	ss(str);
	float			value;

	if (!(ss >> value))
		throw std::runtime_error("Invalid float");
	return value;
}

void	BitcoinExchange::storeDataIntoMap(std::string &line)
{
	size_t pos = line.find(",");
	std::string date = line.substr(0, pos);
	std::string value = line.substr(pos + 3);

	try {
		if (isValidDate(date) && isValidValue(value))
		{
			float copy = convertToFloat(value);
			this->_btc[date] = copy;
		}
		else
		{
			std::cerr << "Error: Invalid date or value in line: " << line << std::endl;
		}
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << " in line: " << line << std::endl;
	}
}


/* ------------------------------------------------------------ */

void	BitcoinExchange::process(void)
{
	for (std::map<std::string,float>::iterator it=_btc.begin(); it!=_btc.end(); ++it)
		std::cout << "First: " << it->first << ", Second: " << it->second << std::endl;
}

void	BitcoinExchange::parse(char *av)
{
	std::ifstream	file(av);

	if (file.is_open())
	{
		std::string	line;
		std::string	first_line;

		std::getline(file, first_line);
		if (first_line != "date | value")
		{
			std::cerr << "First Line Should Be A Header :(" << std::endl;
			return ;
		}
		std::cout << first_line << std::endl;
		for (std::string line; std::getline(file, line);)
			storeDataIntoMap(line);
		return ;
	}
	std::cerr << "File wasn't found" << std::endl;
	return ;	
}

void	BitcoinExchange::fillInMap(const char *data_file)
{
	std::ifstream	file(data_file);
	if (file.is_open())
	{
		std::string	line;
		std::string	first_line;

		std::getline(file, first_line);
		std::cout << first_line << std::endl;
		for (std::string line; std::getline(file, line);)
			storeDataIntoMap(line);
	}
	else
		std::cerr << "An error occurred in Database" << std::endl;
}
