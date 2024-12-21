#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>
#include <sstream>
#include <string>
#include <limits>
#include <cstdlib>
#include "FJMIVect.hpp"

class PmergeMe {
	private:
		double			_vecTime;
		double			_listTime;

		std::vector<int>	_vec;
		std::list<int>		_list;

	public:
		PmergeMe(void);
		~PmergeMe(void);
		PmergeMe(PmergeMe const &src);
		PmergeMe &operator=(PmergeMe const &src);

		std::vector<int>	getVec(void) const;
		double          	getVecTime(void) const;

		std::list<int>	getList(void) const;
		double			getListTime(void) const;

		bool	parse(char **av);
		void	fillInContainers(char **av);
		void	displayResults(void);

		std::vector<int>	MISVect(std::vector<int> arr);
		std::list<int>		MISList(std::list<int> arr);
};

#endif

