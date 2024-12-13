# include "BitcoinExchange.hpp"
# include <cstring>
# include <fstream> // for read/write file streams


int	main(int ac, char **av)
{
	if (ac == 2)
	{
		BitcoinExchange	obj;
		obj.parse(av[1]);
		return 0;
	}
	std::cout << "Error: could not open file." << std::endl;
	return 0;
}
