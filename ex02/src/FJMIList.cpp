#include "FJMIList.hpp"

FJMIList::FJMIList(void) {}

FJMIList::~FJMIList(void) {}

FJMIList::FJMIList(FJMIList const &src) {
	(void) src;
}

FJMIList& FJMIList::operator=(FJMIList const &src) {
	(void) src;
	return *this;
}

/* ---------------------------------------------------------- */

int	FJMIList::jacobstha(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	return jacobstha(n - 1) + 2 * jacobstha(n - 2);
}

/* ---------------------------------------------------------- */


std::list<int> FJMIList::build_jacob_insertion_sequence(int size) {
    std::list<int> sequence;
    int index = 3; // Start at 3 as the first relevant Jacobsthal number

    while (jacobstha(index) < size - 1) {
        sequence.push_back(jacobstha(index));
        ++index;
    }

    return sequence;
}

std::list<std::list<int> > FJMIList::create_pairs(std::list<int> &array) {
    std::list<std::list<int> > pairs;
    std::list<int> temp_pair;

    for (std::list<int>::iterator it = array.begin(); it != array.end(); ++it) {
        if (temp_pair.size() == 1) {
            temp_pair.push_back(*it);
            pairs.push_back(temp_pair);
            temp_pair.clear();
        } else if (pairs.size() * 2 == array.size() - 1) {
            temp_pair.push_back(*it);
            pairs.push_back(temp_pair);
        } else {
            temp_pair.push_back(*it);
        }
    }

    return pairs;
}

void FJMIList::sort_each_pair(std::list<std::list<int> > &pairs) {
    for (std::list<std::list<int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
        if (it->size() == 2) {
            std::list<int>::iterator first = it->begin();
            std::list<int>::iterator second = ++it->begin();

            if (*first > *second) {
                std::swap(*first, *second);
            }
        }
    }
}

void FJMIList::insertion_sort_pairs(std::list<std::list<int> > &pairs) {
    for (std::list<std::list<int> >::iterator it = ++pairs.begin(); it != pairs.end(); ++it) {
        std::list<int> key = *it;
        std::list<std::list<int> >::iterator jt = it;

        while (jt != pairs.begin()) {
            std::list<std::list<int> >::iterator prev = jt;
            --prev;

            if (prev->back() <= key.back()) {
                break;
            }

            *jt = *prev;
            jt = prev;
        }

        *jt = key;
    }
}

std::list<int> FJMIList::create_s(
    std::list<std::list<int> > &pairs,
    int straggler)
{
    std::list<int> S;
    std::list<int> pend;
    int comparisons_made = 0;

    for (std::list<std::list<int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
        if (it->size() == 2) {
            S.push_back(it->back());
            pend.push_back(it->front());
        } else {
            S.push_back(it->front());
        }
    }

    if (!pend.empty()) {
        S.push_front(pend.front());
        pend.pop_front();
    }

    std::list<int> jacob_sequence = build_jacob_insertion_sequence(pend.size());

    std::list<int>::iterator pend_it = pend.begin();
    while (pend_it != pend.end()) {
        int item;
        if (!jacob_sequence.empty()) {
            std::list<int>::iterator seq_it = jacob_sequence.begin();
            std::advance(pend_it, *seq_it - 1);
            item = *pend_it;
            jacob_sequence.pop_front();
        } else {
            item = *pend_it;
            ++pend_it;
        }

        std::list<int>::iterator insertion_point = std::lower_bound(S.begin(), S.end(), item);
        S.insert(insertion_point, item);
        comparisons_made += 2;
    }

    if (straggler != -1) {
        std::list<int>::iterator insertion_point = std::lower_bound(S.begin(), S.end(), straggler);
        S.insert(insertion_point, straggler);
        comparisons_made += 2;
    }

    return S;
}

