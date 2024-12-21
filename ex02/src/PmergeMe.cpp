# include "PmergeMe.hpp"
#include "FJMIVect.hpp"
#include "FJMIList.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::~PmergeMe(void) {}

PmergeMe::PmergeMe(PmergeMe const &src) : 
	_vecTime(src._vecTime)
	{}

PmergeMe& PmergeMe::operator=(PmergeMe const &src) {
	if (this != &src)
	{
		_vecTime = src._vecTime;
	}
	return *this;
}


bool	PmergeMe::parse(char **av)
{
	int	i = 1;

	while (av[i] != NULL)
	{
		char* 	endptr;
		long	number = std::strtol(av[i], &endptr, 10);

		if (*endptr != '\0' || number <= 0 || number > std::numeric_limits<int>::max()) 
			return false;
		i++;
	}
	return (true);
}

void	PmergeMe::fillInContainers(char **av)
{
	int	i = 1;
	
	while (av[i] != NULL)
	{
		char*	endptr;
		long	number = std::strtol(av[i], &endptr, 10);
		if (*endptr != '\0' || number <= 0 || number > std::numeric_limits<int>::max()) 
			throw std::runtime_error("Invalid input");
		this->_vec.push_back(static_cast<int>(number));
		this->_list.push_back(static_cast<int>(number));
		i++;
	}
}

std::vector<int>	PmergeMe::MISVect(std::vector<int> array)
{
	FJMIVect	fjmi;

	/*
	std::cout << "Starting Array:" << std::endl;
	for (size_t i = 0; i < array.size(); ++i) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
	*/

	int straggler = -1;
	if (array.size() % 2 != 0) {
		straggler = array.back();
		array.pop_back();
	}
	std::vector<std::vector<int> > pairs = fjmi.create_pairs(array);
	fjmi.sort_each_pair(pairs);
	fjmi.insertion_sort_pairs(pairs);
	std::vector<int> sorted_array = fjmi.create_s(pairs, straggler);

	/*
	std::cout << "After sorting :" << std::endl;
	for (size_t i = 0; i < sorted_array.size(); ++i) {
		std::cout << sorted_array[i] << " ";
	}
	std::cout << std::endl;
	*/

	return sorted_array;
}

std::list<int>          PmergeMe::MISList(std::list<int> input)
{
	FJMIList	fjmi;
	bool has_straggler = input.size() % 2 != 0;
	int straggler = -1;

	if (has_straggler) {
		straggler = input.back();
		input.pop_back();
	}

	// Create pairs
	std::list<std::list<int> > pairs = fjmi.create_pairs(input);

	// Sort each pair
	fjmi.sort_each_pair(pairs);

	// Recursively sort pairs by their largest value
	fjmi.insertion_sort_pairs(pairs);

	// Merge sorted pairs into final sorted list
	std::list<int> sorted = fjmi.create_s(pairs, straggler);
	return sorted;
}

void	PmergeMe::displayResults(void)
{
	std::clock_t	start;
	std::clock_t	end;

	start = std::clock();
	this->_vec = MISVect(this->_vec);
	end = std::clock();
	_vecTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;

	
	start = std::clock();
	this->_list = MISList(this->_list);
	end = std::clock();
	_listTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;
}

std::vector<int>        PmergeMe::getVec(void) const
{
	return this->_vec;
}

double		PmergeMe::getVecTime(void) const
{
	return this->_vecTime;
}


std::list<int>		PmergeMe::getList(void) const
{
	return this->_list;
}

double		PmergeMe::getListTime(void) const
{
	return this->_listTime;
}
