#include "iter.h"

int	main(void) {

	int arr[3] = {1, 2, 3};
	my_iterator<int>(arr, 3, print);

	std::cout << "\n\n";

	char arr2[3] = {'a', 'c', 'd'};
	my_iterator<char>(arr2, 3, print);


	std::cout << "\n\n";

	std::string	arr3[3] = {
		"one",
		"two", 
		"three"
	};
	my_iterator<std::string>(arr3, 3, print);
	
	return 0;
}
