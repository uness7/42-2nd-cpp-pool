#include "ScalarConverter.h"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
	ScalarConverter::convert(av[1]);
	std::cout << "\n";
	}
	else
		std::cout << "Not enough params." << std::endl;

	return (0);
}
