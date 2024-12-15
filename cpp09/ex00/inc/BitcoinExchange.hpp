# ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <algorithm>
# include <string>
# include <sstream>
# include <fstream>
# include <map>

class BitcoinExchange {
	public:
		std::map<std::string, float>	_btc;
		
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange &operator=(BitcoinExchange const &src);

		std::map<std::string, float>	getBtc(void) const;

		void	fillInMap(const char* data_file);
		void	process(void);
		void	parse(char *av);
		void	storeDataIntoMap(std::string & line);
};

# endif
