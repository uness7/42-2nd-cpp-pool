#include "BitcoinExchange.hpp"

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

void    trim(char* str) {
        char* start = str;                                                                     
        while (*start && (*start == ' ' || *start == '\t')) {
                start++;                                                                       
        }
        char* end = start + strlen(start) - 1;                                                 
        while (end > start && (*end == ' ' || *end == '\t')) {                                 
                *end = '\0';                                                                   
                end--;                                                                         
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
			std::cerr << "ERror" << std::endl;
			return ;
		}
		for (std::string line; std::getline(file, line);)
		{
			std::cout << line << std::endl;
		}
		return ;
	}
	std::cerr << "File wasn't found" << std::endl;
	return ;	
}

