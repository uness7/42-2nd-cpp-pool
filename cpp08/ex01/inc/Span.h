#ifndef SPAN_H
#define SPAN_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Span {
	private:
		unsigned int	_n;
		std::vector<int>	_numbers;


	public:
		Span(void);
		Span(unsigned int n);
		~Span(void);
		//Span(Span const & other);
		//Span &operator =(Span const & other);

		std::vector<int>	getNumbers(void) const;
		unsigned int		getN(void) const;

		void		addNumber(int number);
		int		shortestSpan(void);
		int		longestSpan(void);
		void    	addNumbers(int numbers);
		
		template <typename It>
		void	addNumber(It begin, It end)
		{
			while (begin != end)
			{
				this->addNumber(*begin);
				begin++;
			}
		}


		class MaxIntegersReachedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class NoSpanPossibleException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
