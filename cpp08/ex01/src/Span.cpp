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

void	Span::addNumber(int number)
{
	if (this->_numbers.size() >= this->_n)
		throw MaxIntegersReachedException();
	this->_numbers.push_back(number);
}

const char*	Span::MaxIntegersReachedException::what() const throw()
{
	return "Max of integers possible to store was reached!\n";
}

