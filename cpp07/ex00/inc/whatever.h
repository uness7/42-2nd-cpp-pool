# ifndef WHATEVER_H
# define WHATEVER_H

# include <iostream>

/************ swap *******************/
template <class T>
void
my_swap(T& a, T& b) {
    T   c;

    c = a;
    a = b;
    b = c;
    return ;
}

/*********** min ******************/
template <class T>
T
my_min(T& a, T& b) {
    T   min;

    min = a;
    if (min > b)
        return min;
    return min;
}

/*********** max ******************/
template <class T>
T
my_max(T& a, T& b) {
    T   max;

    max = a;
    if (max < b)
        max = b;
    return max;
}

# endif


