# include "Array.h"

int main(void) {
	Array<int> my_arr(2);

	my_arr[0] = 2;
	my_arr[1] = 4;


	std::cout << my_arr[1] << std::endl;
	std::cout << my_arr[0] << std::endl;


	Array<char>	my_char_arr(3);
	my_char_arr[0] = 'W';
	my_char_arr[1] = 'A';
	my_char_arr[2] = 'C';

	std::cout << my_char_arr[0] << my_char_arr[1] << my_char_arr[2] << std::endl;


	Array<std::string>	my_string_arr(4);

	my_string_arr[0] = "One";
	my_string_arr[1] = "Two";
	my_string_arr[2] = "Three";
	my_string_arr[3] = "Four";

	for (unsigned int i = 0; i < my_string_arr.getSize() ; i++)
		std::cout << my_string_arr[i] << std::endl;
}
