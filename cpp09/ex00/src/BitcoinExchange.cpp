#include "BitcoinExchange.hpp"
#include "Utils.hpp"

BitcoinExchange::BitcoinExchange(void) {}
BitcoinExchange::~BitcoinExchange(void) {}
BitcoinExchange::BitcoinExchange(BitcoinExchange const & src) { (void)src; }
BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const & src) { (void)src; return *this; }

/* ------------------------------------------------------------ */

std::map<std::string, float>	BitcoinExchange::getBtc(void) const
{
	return this->_btc;
}

/* ------------------------------------------------------------ */

bool	BitcoinExchange::isDateAndValueValid(std::string &date, std::string &value)
{
	Utils	utils;

	if (!utils.isValidValue(value))
	{
		if (value[0] == '-')
			std::cout << "Error: not a positive number"  << std::endl;
		else
			std::cout << "Error: too large a number"  << std::endl;
		return false;
	} else if (!utils.isValidDate(date)) {
		std::cout << "Error: bad input => " << date << std::endl;
		return false;
	}
	
	return true;
}

bool	BitcoinExchange::isLineValid(std::string &line)
{
	Utils	utils;	

	if (line.empty())
	{
		std::cout << "Error: bad input" << std::endl;
		return false;
	}
	
	size_t	pos = line.find(" | ");
	if (pos == std::string::npos)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return false;
	}

	std::string	date = line.substr(0, pos);
	std::string	value = line.substr(pos + 3);
	
	if (!isDateAndValueValid(date, value))
		return false;
	return true;
}

void	BitcoinExchange::process(std::string &line)
{
	//for (std::map<std::string,float>::iterator it=_btc.begin(); it!=_btc.end(); ++it)
	//	std::cout << "First: " << it->first << ", Second: " << it->second << std::endl;
	if (isLineValid(line))
	{
		Utils	utils;
		size_t	pos = line.find(" | ");
		if (pos == std::string::npos)
		{
			std::cout << "Error: bad input" << std::endl;
			return ;
		}
		std::string	date = line.substr(0, pos);
		std::string	value = line.substr(pos + 3);

		try {
			double rate_exchange = this->_btc.at(date);
			float	numeric_value = utils.convertToFloat(value);
			double	result = numeric_value * rate_exchange;
			std::cout << date << " => " << value << " = " << result << std::endl;
		} catch (std::exception &e) {
			std::map<std::string,float>::iterator 
				it = this->_btc.lower_bound(date);
			if (it == this->_btc.begin())
				return ;
			--it;
			float numeric_value = utils.convertToFloat(value);
            		double result = numeric_value * it->second;
			std::cout << date << " => " << value << " = " << result << " (using rate from " << it->first << ")" << std::endl;
			
		}
		return ;
	}
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
		//std::cout << first_line << std::endl;
		(void)first_line;
		for (std::string line; std::getline(file, line);)
			process(line);
		return ;
	}
	std::cerr << "File wasn't found" << std::endl;
	return ;	
}

void	BitcoinExchange::fillInMap(const char *data_file)
{
	std::ifstream	file(data_file);
	Utils		utils;

	if (file.is_open())
	{
		std::string	line;
		std::string	first_line;

		std::getline(file, first_line);
		(void)line;
		for (std::string line; std::getline(file, line);)
		{
			std::string	arr[2];
			int		index = 0;
			char		del = ',';

			utils.split_line(line, del, arr, index);	
			float float_value = utils.convertToFloat(arr[1]);
			this->_btc[arr[0]] = float_value;
		}
	}
	else
		std::cerr << "An error occurred in Database" << std::endl;
}
