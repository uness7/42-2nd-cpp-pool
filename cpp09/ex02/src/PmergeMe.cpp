# include "PmergeMe.hpp"


PmergeMe::PmergeMe(void) {}

PmergeMe::~PmergeMe(void) {}

PmergeMe::PmergeMe(PmergeMe const &src) : _vecTime(src._vecTime), _listTime(src._listTime) {}

PmergeMe& PmergeMe::operator=(PmergeMe const &src) {
	if (this != &src)
	{
		_vecTime = src._vecTime;
		_listTime = src._listTime;
	}
	return *this;
}

/* ------------------------------------------------------------------------------- */

bool	PmergeMe::parse(char **av)
{
	int	i = 1;

	while (av[i] != NULL)
	{
		char* endptr;
		long number = std::strtol(av[i], &endptr, 10);
		if (*endptr != '\0' || number <= 0 || number > std::numeric_limits<int>::max()) 
			return false;
		i++;
	}
	return true;
}

void	PmergeMe::fillInContainers(char **av)
{
	int	i = 1;
	
	while (av[i] != NULL)
	{
		char*	endptr;
		long	number = std::strtol(av[i], &endptr, 10);
		if (*endptr != '\0' || number <= 0 || number > std::numeric_limits<int>::max()) 
		{
			throw std::runtime_error("Invalid input");
		}
		this->_vec.push_back(static_cast<int>(number));
		this->_list.push_back(static_cast<int>(number));
		i++;
	}
}

/* ------------------------------------------------------------------------------- */

void	PmergeMe::sort(void)
{
	std::clock_t	start;
	std::clock_t	end;

	/* Vector */
	start = std::clock();
	fordJohnsonSort(this->_vec);
	end = std::clock();
	_vecTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;

	/* List */
	start = std::clock();
	fordJohnsonSort(this->_list);
	end = std::clock();
	_listTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;
}

void	PmergeMe::displayVect(std::vector<int>	&vec)
{
	int	i = 0;
	while (vec[i])
		std::cout << vec[i++] << " ";
}

void	PmergeMe::display(void)
{
	// before sorting
	std::cout << "Before: ";
	PmergeMe::displayVect(this->_vec);
	std::cout << std::endl;

	// sorting
	PmergeMe::sort();
	std::cout << "After: ";

	// after sorting
	PmergeMe::displayVect(this->_vec);
	std::cout << std::endl;
	std::cout << "Time to process a range of " << this->_vec.size() << " elements with std::vector<int> : " << std::fixed << std::setprecision(6) << this->_vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << this->_list.size() << " elements with std::list<int> : " << std::fixed << std::setprecision(6) << this->_listTime << " us" << std::endl;
}

bool	PmergeMe::isSorted(void)
{
	for (size_t i = 0; i + 1 < this->_vec.size(); ++i)
		if (_vec[i] > _vec[i + 1])
			return false;
	return true;
}

bool	PmergeMe::hasDuplicates(void)
{
	std::vector<int>	copy = _vec;
	std::sort(copy.begin(), copy.end());
	return std::adjacent_find(copy.begin(), copy.end()) != copy.end();
}
