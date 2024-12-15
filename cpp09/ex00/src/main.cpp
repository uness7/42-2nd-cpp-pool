# include "BitcoinExchange.hpp"
# include <cstring>
# include <fstream> // for read/write file streams


int	main(int ac, char **av)
{
	(void)av;
	if (ac == 2)
	{
		BitcoinExchange	obj;
		const char* data_file = "data.csv";
		obj.fillInMap(data_file);
		//obj.parse(av[1]);
		//obj.process();
		return 0;
	}
	std::cout << "Error: could not open file." << std::endl;
	return 0;
}
