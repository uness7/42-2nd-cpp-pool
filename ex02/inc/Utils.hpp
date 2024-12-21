#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

template <typename T>
class Utils {
private:
	Utils(void) {};
	Utils(Utils const &src) {(void) src;};
	Utils &operator=(Utils const &src) {(void) src; return *this;};

public:
	~Utils(void);

	/* ---------------------------------------------------------------------- */

	static bool	isSorted(const std::vector<T> &vec)
	{
		if (vec.empty() || vec.size() == 1)
			return (true);
		for (size_t i = 1; i < vec.size(); ++i)
			if (vec[i] < vec[i - 1])
				return (false);
		return (true);
	}

	static bool	isSorted(const std::list<T> &list)
	{
		if (list.empty() || list.size() == 1)
			return (true);
		typename std::list<T>::const_iterator it = list.begin();
		typename std::list<T>::const_iterator prev = it++;
		while (it != list.end())
		{
			if (*it < *prev)
				return (false);
			prev = it++;
		}
		return (true);
	}

	/* ---------------------------------------------------------------------- */

	static bool	hasDuplicates(const std::list<T> &list)
	{
		if (list.empty() || list.size() == 1)
			return (false);
		typename std::list<T>::const_iterator it1;
		typename std::list<T>::const_iterator it2;
		for (it1 = list.begin(); it1 != list.end(); ++it1)
		{
			it2 = it1;
			++it2;
			for (; it2 != list.end(); ++it2)
			{
				if (*it1 == *it2)
					return true;
			}
		}
		return false;
	}

	static bool	hasDuplicates(const std::vector<T> &vec)
	{
		if (vec.empty() || vec.size() == 1)
			return (false);
		
		for (size_t i = 0; i < vec.size(); ++i)
		{
			for (size_t j = i + 1; j < vec.size(); ++j)
				if (vec[i] == vec[j])
					return (true);
		}	
		return (false);
	}

	/* ---------------------------------------------------------------------- */

	static void	display(const std::list<T> &list)
	{
		if (list.empty())
		{
			std::cout << "Vector is empty" << std::endl;
			return ;
		}
		typename std::list<T>::const_iterator	it = list.begin();
		for (it = list.begin(); it != list.end(); ++it)
			std::cout << *it << " ";
	}

	static void	display(const std::vector<T> &vec)
	{
		if (vec.empty())
		{
			std::cout << "Vector is empty" << std::endl;
			return ;
		}
		for (size_t i = 0; i < vec.size(); ++i)
			std::cout << vec[i] << " ";
	}

	/* ---------------------------------------------------------------------- */
	/* 		   		    The End 				  */
};

#endif
