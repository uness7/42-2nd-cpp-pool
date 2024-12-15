#include "RPN.hpp"

int	main(int ac, char *av[])
{
	if (ac == 2)
	{
		RPN	rpn;
		rpn.process(av[1]);
	}
	else
		std::cerr << "This program takes in one argument" << std::endl; 
	return 0;
}
