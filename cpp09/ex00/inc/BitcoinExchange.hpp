# ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <algorithm>
# include <string>
# include <map>
# include <cstring>
# include <fstream>

class BitcoinExchange {
	private:
		std::map<std::string, int>	_btc;
	
	public:
		BitcoinExchange(void);
		~BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange &operator=(BitcoinExchange const &src);


		std::map<std::string, int>	getBtc(void)	const;
		void				parse(char *av);
};


/* Non-member functions */
void    trim(char* str);
void    splitString(std::string input, char* date, char* value);


# endif
