#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <iostream>
#include <algorithm>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
        public:
                MutantStack(void) : std::stack<T>() {}
                MutantStack(MutantStack const & src) : std::stack<T>(src) { }
                MutantStack& operator=(MutantStack const & rhs)
                {
                        if (this != &rhs)
                                std::stack<T>::operator=(rhs);
                        return *this;
                }
                ~MutantStack(void) {}

                typedef typename std::stack<T>::container_type::iterator        iterator;

                iterator begin() { return this->c.begin(); }
                iterator end()   { return this->c.end(); }
};

#endif
