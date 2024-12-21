#include "PmergeMe.hpp"
#include "Utils.hpp"
#include <iomanip>

int	main(int ac, char **av)
{
	if (ac > 2)
	{
		PmergeMe	obj;

		if (obj.parse(av) == false)
		{
			std::cout << "The sequence contains a negative value or 0" << std::endl;
			return -1;
		} else {
			obj.fillInContainers(av);
			if (!Utils<int>::isSorted(obj.getVec()) && !Utils<int>::hasDuplicates(obj.getVec())) 
			{

				std::cout << "Before: ";
				Utils<int>::display(obj.getVec());

				obj.displayResults();

				std::cout << "\nAfter: ";
				Utils<int>::display(obj.getVec());
				std::cout << "\nTime to process a range of " << obj.getVec().size() << " elements with std::vector<int> : " 
					<< std::fixed << std::setprecision(6) << obj.getVecTime() << " us" << std::endl;
				std::cout << "\nTime to process a range of " << obj.getList().size() << " elements with std::list<int> : " 
					<< std::fixed << std::setprecision(6) << obj.getListTime() << " us" << std::endl;

			} else {
				std::cout << "The sequence is already sorted or has duplicates! " << std::endl;
				return -1;
			}
		}
	} else {
		std::cout << "Not enough args" << std::endl;
	}
	return (0);
}
