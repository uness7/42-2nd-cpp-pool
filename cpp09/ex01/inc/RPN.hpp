#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <sstream>

#include <stdlib.h>
#include<cstdio>

class RPN {
	public:
		RPN();
		~RPN();
		RPN(RPN const &src);
		RPN &operator=(RPN const &src);
		
		void	process(char *av);
		void    split_string(std::string &input, char del, std::string arr[], 
			int &index);
};

#endif
