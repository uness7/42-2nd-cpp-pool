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

void RPN::process(char *av)
{
	MutantStack<int> my_stack;
	std::string str(av);
	std::string arr[100];
	int index = 0;
	char del = ' ';

	split_string(str, del, arr, index);

	for (int i = 0; !arr[i].empty(); ++i)
	{
		std::stringstream ss(arr[i]);
		int number;

		// If it's a number
		if (ss >> number && ss.eof())
		{
			my_stack.push(number);
		}
		// If it's an operator
		else if (arr[i].length() == 1 && std::string("+-*/").find(arr[i]) != std::string::npos)
		{
			if (my_stack.size() < 2)
			{
				std::cerr << "Error: Insufficient operands" << std::endl;
				return;
			}

			int b = my_stack.top(); my_stack.pop();
			int a = my_stack.top(); my_stack.pop();

			switch(arr[i][0])
			{
				case '+': my_stack.push(a + b); break;
				case '-': my_stack.push(a - b); break;
				case '*': my_stack.push(a * b); break;
				case '/': 
					  if (b == 0)
					  {
						  std::cerr << "Error: Division by zero" << std::endl;
						  return;
					  }
					  my_stack.push(a / b);
					  break;
			}
		}
		else
		{
			std::cerr << "Error: Invalid token: " << arr[i] << std::endl;
			return;
		}
	}

	if (!my_stack.empty())
	{
		std::cout << "Result: " << my_stack.top() << std::endl;
	}
	else
	{
		std::cerr << "Error: No result" << std::endl;
	}
}
