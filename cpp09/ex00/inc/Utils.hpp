#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <string>
#include <sstream>

class Utils {
	public:
		Utils(void);
		~Utils(void);
		Utils(Utils const &src);
		Utils &operator=(Utils const &src);


		bool	isValidDate(std::string &date);
		bool	isValidValue(std::string &value);
		float	convertToFloat(std::string const &str);
		void	split_line(std::string &line, char del, 
				std::string arr[], int& index);
};

#endif
