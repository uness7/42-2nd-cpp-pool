# include "PmergeMe.hpp"


PmergeMe::PmergeMe(void) {}
PmergeMe::~PmergeMe(void) {}
PmergeMe::PmergeMe(PmergeMe const &src) {
	(void)src;
}
PmergeMe& PmergeMe::operator=(PmergeMe const &src) {
	(void)src;
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

std::vector<int>	PmergeMe::getVec(void)	const
{
	return this->_vec;
}

/* ------------------------------------------------------------------------------- */

void	mergeSortedAndSmaller(std::vector<int>& sorted, const std::vector<int>& smaller)
{
	for (size_t i = 0; i < smaller.size(); ++i)
	{
		std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), smaller[i]);
		sorted.insert(pos, smaller[i]);
	}
}

std::vector<int>	recursiveSort(std::vector<int> &vec)
{
	if (vec.size() <= 1)
		return vec;

	/* divide into pairs */
	std::vector<int>	smaller;	
	std::vector<int>	larger;	
	
	for (size_t i = 0; i + 1 <= vec.size(); i += 2)
	{
		if (vec[i] < vec[i + 1])
		{
			smaller.push_back(vec[i]);
			larger.push_back(vec[i + 1]);
		} else {
			larger.push_back(vec[i]);
			smaller.push_back(vec[i + 1]);
		}
	}
	
	/* Handle odd element */
	if (vec.size() % 2 == 1) larger.push_back(vec.back());
	
	std::vector<int>	sortedVec = recursiveSort(larger);
	
	/* merge and sort */
	mergeSortedAndSmaller(sortedVec, smaller);
	
	return sortedVec;
}

void	fordJohnsonSort(std::vector<int> &vec)
{
	vec = recursiveSort(vec);
}

void	PmergeMe::sort(void)
{
	fordJohnsonSort(this->_vec);
}

void	PmergeMe::display(void)
{
	int	i = 0;
	while (this->_vec[i])
		std::cout << this->_vec[i++] << " ";
	std::cout << std::endl;
}
