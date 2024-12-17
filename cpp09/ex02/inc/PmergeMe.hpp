#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <limits>
#include <vector>
#include <deque>
#include <list>

class PmergeMe {
	private:
		std::vector<int>	_vec;
		std::list<int>		_list;
		double	_vecTime;
		double	_listTime;

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(PmergeMe const &src);
		PmergeMe &operator=(PmergeMe const &src);

		std::vector<int>	getVec(void) const;

		bool	parse(char **av);
		void	fillInContainers(char **av);
		void	sort(void);
		void	display(void);
};

#endif
