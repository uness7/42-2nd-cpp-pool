#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

Base *generate(void) {
	srand(time(0));
	int ran = rand() % 3;
	Base *ret;
	switch (ran) {
		case 0:
			ret = new A();
			break;
		case 1:
			ret = new B();
			break;
		case 2:
			ret = new C();
			break;
	}
	return ret;
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cerr << "Error: Unknown type" << std::endl;
}

void	identify(Base &p)
{
	try {
		if (dynamic_cast<A *>(&p))
			std::cout << "A" << std::endl;
		else if (dynamic_cast<B *>(&p))
			std::cout << "B" << std::endl;
		else if (dynamic_cast<C *>(&p))
			std::cout << "C" << std::endl;
		else
			std::cout << "Unknown type !" << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

int main(int, char **)
{
    Base *b(generate());
    identify(*b);
    identify(b);
    identify(NULL);
    delete b;
    return 0;
}
