# ifndef ITER_H
# define ITER_H

# include <iostream>

template <typename T>

void	print(T a)
{
	std::cout << a << std::endl;
}

/******** iter function ***********/

template <typename T>
void
my_iterator(T *arr, size_t len, void (*f)(T)) {
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}


# endif 
