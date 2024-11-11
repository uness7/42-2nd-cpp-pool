#ifndef EASYFIND_H
#define EASYFIND_H

#include <iostream>
#include <list>
#include <algorithm>    // std::find

template <typename T>

int	easy_find(std::list<T> arr, int to_find)
{
	std::list<int>::const_iterator	it;

	it = std::find(arr.begin(), arr.end(), to_find);
	if (it != arr.end())
		return (0);
	return (-1);
}

#endif
