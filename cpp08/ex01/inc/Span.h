#ifndef SPAN_H
#define SPAN_H

#include <iostream>
#include <vector>

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
		//

		std::vector<int>	getNumbers(void) const;

		void		addNumber(int number);

//		void		shortestSpan();

//		void		longestSpan();

		// add a function to add as many numbers as we wish in one call using iterators!
		//


		class MaxIntegersReachedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
