# ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <algorithm>
# include <string>
# include <sstream>
# include <fstream>
# include <map>
# include <limits>

class BitcoinExchange {
	public:
		std::map<std::string, float>	_btc;
		
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange &operator=(BitcoinExchange const &src);

		std::map<std::string, float>	getBtc(void) const;

		void	fillInMap(const char* data_file);
		void	process(std::string& line);
		void	parse(char *av);
		bool	isLineValid(std::string &line);
		bool	isDateAndValueValid(std::string &date, std::string &value);

};

# endif
