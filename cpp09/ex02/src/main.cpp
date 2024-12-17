#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac > 2)
	{
		PmergeMe	obj;
		if (!obj.parse(av))
		{
			std::cout << "not fine" << std::endl;
			return -1;
		}
		obj.fillInContainers(av);
		std::cout << "before" << std::endl;
		obj.display();
		obj.sort();
		std::cout << "\n\n\n\n\n\n\n\n\n" << std::endl;
		std::cout << "after" << std::endl;
		obj.display();
	}
	else
	{
		std::cout << "Not enough args" << std::endl;
	}
	return 0;
}
