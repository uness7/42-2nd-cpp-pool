# include "BitcoinExchange.h"
# include <cstring>
# include <fstream> // for read/write file streams


void	trim(char* str) {
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

void	splitString(std::string input, char* date, char* value)
{
	c
	char* delimiter = strchr(input, '|');

	date[0] = '\0';
	value[0] = '\0';

	if (delimiter) {
		*delimiter = '\0'; 
		strcpy(date, input.c_str());
		trim(date);
		strcpy(value, delimiter + 1);
		trim(value);
	}
}

void	parser(char *av)
{
	std::ifstream	file(av);

	if (file.is_open())
	{
		std::string	line;
		std::string	first_line;	

		std::getline(file, first_line);
		if (first_line != "date | value")
		{
			std::cerr << "First line of input.txt file must be as follows : date | value" << std::endl;
			return ;
		}
		for (std::string line; std::getline(file, line);)
		{
			// 2010-10-01 | 0
			char	date[40], value[40];
			splitString(line, date, value);

			// Print results
			std::cout << "Date: [" << date << "]" << std::endl;
			std::cout << "Value: [" << value << "]" << std::endl;
		}

	} else {
		std::cerr << "File wasn't found!" << std::endl;
	}
	return ;
}


int	main(int ac, char **av)
{
	if (ac == 2)
	{
		parser(av[1]);
		return 0;
	}
	std::cout << "Error: could not open file." << std::endl;
	return 0;
}
