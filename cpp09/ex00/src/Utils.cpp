#include "Utils.hpp"


Utils::Utils(void) {}
Utils::~Utils(void) {}
Utils::Utils(Utils const &src) {
	(void)src;
}
Utils& Utils::operator=(Utils const &src) {
	(void)src;
	return *this;
}

/* ------------------------------------------------------------- */

bool	Utils::isValidDate(std::string &date)
{
	size_t first = date.find_first_not_of(" \t");
	size_t last = date.find_last_not_of(" \t");
	if (first == std::string::npos || last == std::string::npos)
		return false;
	date = date.substr(first, last - first + 1);

	if (date.length() != 10) return false;
	if (date[4] != '-' || date[7] != '-') return false;

	int yy, mm, dd;
	std::stringstream ss(date);
	char dash1, dash2;

	if (!(ss >> yy >> dash1 >> mm >> dash2 >> dd))
		return false;

	if (yy < 1 || yy > 9999) return false;
	if (mm < 1 || mm > 12) return false;

	int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if ((yy % 4 == 0 && yy % 100 != 0) || (yy % 400 == 0))
		daysInMonth[2] = 29;

	if (dd < 1 || dd > daysInMonth[mm]) return false;

	return true;
}

bool	Utils::isValidValue(std::string &line)
{
	size_t start = line.find_first_not_of(" \t");
	size_t end = line.find_last_not_of(" \t");
	if (start == std::string::npos || end == std::string::npos) {
		return false;
	}
	line = line.substr(start, end - start + 1);

	std::istringstream iss(line);
	double value;
	if (!(iss >> value)) {
		return false;
	}

	std::string extra;
	if (iss >> extra) {
		return false;
	}

	if (value < 0 || value > 1000) {
		return false;
	}

	return true;
}

float	Utils::convertToFloat(std::string const &str)
{
	std::stringstream 	ss(str);
	float			value;

	if (!(ss >> value))
		throw std::runtime_error("Invalid float");
	return value;
}

void	Utils::split_line(std::string&line, char del, std::string arr[], int &index)
{
	std::istringstream	stream(line);
	std::string	token;
	while (getline(stream, token, del))
		arr[index++] = token;	
}
