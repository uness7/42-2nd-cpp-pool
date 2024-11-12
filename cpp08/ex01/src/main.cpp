#include "Span.h"

int	main(int, char **)
{
	Span sp = Span(3);

	try {
		sp.addNumber(99);
		sp.addNumber(990);
		sp.addNumber(993);
		// sp.addNumber(9); this will throw an exception

		std::cout << sp.getNumbers().at(0) << std::endl;
		std::cout << sp.getNumbers().at(1) << std::endl;
		std::cout << sp.getNumbers().at(2) << std::endl;

	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}


	return 0;
}
