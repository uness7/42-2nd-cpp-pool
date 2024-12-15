# include "RPN.hpp"
# include "MutantStack.hpp"
# include <limits>

RPN::RPN(void) {}
RPN::~RPN(void) {}
RPN::RPN(RPN const &src) {
	(void)src;
}
RPN& RPN::operator=(RPN const &src) {
	(void)src;
	return *this;
}

/* -------------------------------------------------------------- */

void	RPN::split_string(std::string &input, char del, std::string arr[], int &index)
{
	std::istringstream	iss(input);
	std::string		token;		
	
	while (getline(iss, token, del))
		arr[index++] = token;
}

void	RPN::process(char *av)
{
	MutantStack<int>	my_stack;
	std::string		str(av);
	std::string		arr[100];
	int			index = 0;
	char			del = ' ';
	
	split_string(str, del, arr, index);
	int	i = 0;
	while (!arr[i].empty())
	{
		//if (std::isdigit(std::atoi(arr[i].c_str())))
		if (std::stringstream(arr[i]) >> std::ws && std::stringstream(arr[i]).peek() != EOF)
		{
			int	number;
			std::stringstream	ss;
			ss << arr[i];
			ss >> number;
			std::cout << "number : " << number << std::endl;
			my_stack.push(number);
		}
		else
		{
			std::cout << "oops it's an op" << std::endl;
			break ;
		}
		i++;
	}


	// displaying the content of my_stack using iterators
	MutantStack<int>::iterator it = my_stack.begin();
        MutantStack<int>::iterator ite = my_stack.end();

	while (it != ite)
		std::cout << *it++ << std::endl;

}
