#include "Span.h"

Span::Span(void)
	: _n(-1) { }

Span::Span(unsigned int n) 
	: _n(n) { }

Span::~Span(void) { }

/*
Span(Span const & other) : _n(other._n) { }

Span(Span const & other)
{
	if (this != &other)
	{
		this->_n = other._n;
	}
	return *this;
}
*/

std::vector<int>	Span::getNumbers(void) const
{
	return this->_numbers;
}

unsigned int	Span::getN(void) const
{
	return this->_n;
}

void	Span::addNumber(int number)
{
	if (this->_numbers.size() == this->_n)
		throw MaxIntegersReachedException();
	this->_numbers.push_back(number);
}

int	Span::shortestSpan(void)
{
	int			diff = -1;
	std::vector<int>	sortedArr;
	int			tmp;

	if (this->_n < 2)
		throw NoSpanPossibleException();
	sortedArr = this->_numbers;
	std::sort(sortedArr.begin(), sortedArr.end());
	tmp = INT_MAX;
	for (int i = 0; i < static_cast<int>(sortedArr.size()); i++)
	{
		for (int j = i + 1; j < static_cast<int>(sortedArr.size()); j++)
		{
			diff = abs(sortedArr.at(i) - sortedArr.at(j));
			tmp = std::min(tmp, diff);
			if (tmp == 1) return 1;
		}
	}
	return (tmp);
}

int	Span::longestSpan(void)
{	
	int			diff = -1;
	std::vector<int>	sortedArr;
	int			tmp;

	if (this->_n < 2)
		throw NoSpanPossibleException();
	sortedArr = this->_numbers;
	std::sort(sortedArr.begin(), sortedArr.end());
	tmp = INT_MIN;
	for (int i = 0; i < static_cast<int>(sortedArr.size()); i++)
	{
		for (int j = i + 1; j < static_cast<int>(sortedArr.size()); j++)
		{
			diff = abs(sortedArr.at(i) - sortedArr.at(j));
			tmp = std::max(tmp, diff);
			if (tmp == 1) return 1;
		}
	}
	return (tmp);

}

const char*	Span::MaxIntegersReachedException::what() const throw()
{
	return "Max of integers possible to store was reached!\n";
}

const char*	Span::NoSpanPossibleException::what() const throw()
{
	return "Not enough numbers in vector to find a span\n";
}
