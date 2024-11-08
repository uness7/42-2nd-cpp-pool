#include "whatever.h" 
#include <string>

int     main(void) {
    int a, b;
    a = 10;
    b = 20;

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    my_swap<int>(a, b);
    std::cout << "\n\n";

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    char x, y;
    x = 'a';
    y = 'b';

    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;

    my_swap<char>(x, y);
    std::cout << "\n\n";

    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;


    std::string one = "One";
    std::string two = "Two";

    std::cout << "one: " << one << std::endl;
    std::cout << "two: " << two << std::endl;

    my_swap<std::string>(one, two);
    std::cout << "\n\n";

    std::cout << "one: " << one << std::endl;
    std::cout << "two: " << two << std::endl;


    /*****************************************************************/
    int num1, num2;
    num1 = 11;
    num2 = 90;

    std::cout << "min: " << my_min<int>(num1, num2) << std::endl;

    /*****************************************************************/
    int num3, num4;
    num3 = 11;
    num4 = 90;

    std::cout << "max: " << my_max<int>(num3, num4) << std::endl;
}
