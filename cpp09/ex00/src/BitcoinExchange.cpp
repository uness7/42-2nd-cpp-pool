#include "BitcoinExchange.hpp"
#include <limits>

BitcoinExchange::BitcoinExchange(void) {}
BitcoinExchange::~BitcoinExchange(void) {}
//BitcoinExchange::BitcoinExchange(BitcoinExchange const & src) { (void)src; }
//BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const & src) { (void)src; return *this; }

/* ------------------------------------------------------------ */

std::map<std::string, int>	BitcoinExchange::getBtc(void) const
{
	return this->_btc;
}

/* ------------------------------------------------------------ */

bool	isValidDate(std::string & date)
{
	if (date.length() != 10) return false;
	if (date[4] != '-' || date[4] != '-') return false;

	int	yy, mm, dd;

	std::stringstream	ss(date);
	char	dash1, dash2;
	
	if (!(ss >> yy >> dash1 >> mm >> dash2 >> dd))
		return false;

	if (yy < 1 || yy > 9999) return false;
	if (mm < 1 || mm > 12) return false;
	if (dd < 1 || dd > 31) return false;	

	return true;
}


bool isValidValue(std::string& line) {
    // Trim whitespace (simple manual implementation)
    std::string::size_type start = line.find_first_not_of(" \t");
    std::string::size_type end = line.find_last_not_of(" \t");
    
    if (start == std::string::npos || end == std::string::npos) {
        return false;
    }
    
    line = line.substr(start, end - start + 1);
    
    // Use stringstream for conversion
    std::istringstream iss(line);
    double value;
    
    // Attempt conversion
    if (!(iss >> value)) {
        return false;
    }
    
    // Check for extra characters
    std::string extra;
    if (iss >> extra) {
        return false;
    }
    
    // Check range
    if (value < 0 || value > 1000) {
        return false;
    }
    
    return true;
}

void	parseLineByLine(std::string line)
{
	if (line.empty())
	{
		std::cout << "It sucks!" << std::endl;
		return ;
	}

	size_t	pos = line.find(" | ");
	if (pos == std::string::npos)
	{
		std::cout << "It sucks!" << std::endl;
		return ;
	}

	std::string	date = line.substr(0, pos);
	std::string	value = line.substr(pos + 3);
	//return isValidDate(date) && isValidValue(value);
	if (isValidDate(date) && isValidValue(value))
		std::cout << "It's fine" << std::endl;
	else 
		std::cout << "It sucks!" << std::endl;
}

/* ------------------------------------------------------------ */

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
			std::cerr << "ERror" << std::endl;
			return ;
		}
		for (std::string line; std::getline(file, line);)
		{
			parseLineByLine(line);
		}
		return ;
	}
	std::cerr << "File wasn't found" << std::endl;
	return ;	
}

