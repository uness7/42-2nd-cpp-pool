#include "Span.h"

int	main(int, char **)
{
	try {
		Span sp = Span(10000);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
	
		std::cout << "Current Size: " << sp.getNumbers().size() << std::endl;
		std::cout << "SHORTEST SPAN: " << sp.shortestSpan() << std::endl;
		std::cout << "LONGEST SPAN: " << sp.longestSpan() << std::endl;

	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n\n";

	try {
		std::vector<int>	vect;
		Span			sp2(10);
		for (int i = 0; i < 10; i++)
			vect.push_back(rand() % 100);
		sp2.addNumber(vect.begin(), vect.end());

		std::cout << "Current Size: " << sp2.getNumbers().size() << std::endl;
		std::cout << "SHORTEST SPAN: " << sp2.shortestSpan() << std::endl;
		std::cout << "LONGEST SPAN: " << sp2.longestSpan() << std::endl;

	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
