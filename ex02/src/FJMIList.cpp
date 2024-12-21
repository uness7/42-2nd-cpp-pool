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

std::list<std::list<int> >
FJMIList::create_pairs(std::list<int> &input)
{
	std::list<std::list<int> > pairs;
	std::list<int>::const_iterator it = input.begin();
	while (it != input.end()) {
		std::list<int> pair;
		pair.push_back(*it++);
		if (it != input.end()) {
			pair.push_back(*it++);
		}
		pairs.push_back(pair);
	}
	return pairs;
}

/* ---------------------------------------------------------- */

void
FJMIList::sort_each_pair(std::list<std::list<int> >& pairs) {
    for (std::list<std::list<int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
        if (it->size() == 2) {
            std::list<int>::iterator first = it->begin();
            std::list<int>::iterator second = first;
            ++second; // Move to the next element
            if (*first > *second) {
                std::swap(*first, *second);
            }
        }
    }
}


/* ---------------------------------------------------------- */

void
FJMIList::insert_into_sorted(std::list<int> &sorted, int value)
{
	std::list<int>::iterator it = sorted.begin();
	while (it != sorted.end() && *it < value)
		++it;
	sorted.insert(it, value);
}

/* ---------------------------------------------------------- */

void
FJMIList::insertion_sort_pairs(std::list<std::list<int> > &pairs)
{
	std::list<std::list<int> > sorted;
	std::list<std::list<int> >::iterator	it;
	for (it = pairs.begin(); it != pairs.end(); ++it) {
		std::list<std::list<int> >::iterator sorted_it = sorted.begin();
		while (sorted_it != sorted.end() && it->back() > sorted_it->back()) {
			++sorted_it;
		}
		sorted.insert(sorted_it, *it);
	}
	pairs = sorted;
}

/* ---------------------------------------------------------- */

std::list<int>
FJMIList::build_jacob_insertion_sequence(int size)
{
	std::list<int> sequence;
	sequence.push_back(0); // Base case
	sequence.push_back(1); // Base case

	while (true) {
		int jacob = sequence.back() + 2 * *(--(--sequence.end())); // Last and second last values
		if (jacob >= size) break;
		sequence.push_back(jacob);
	}

	return sequence;
}

/* ---------------------------------------------------------- */

std::list<int>
FJMIList::create_s(std::list<std::list<int> > &pairs, int straggler)
{
	std::list<int> S;
	std::list<int> pend;

	// Separate the larger and smaller values
	for (std::list<std::list<int> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it) {
		std::list<int>::const_iterator pair_it = it->begin();
		S.push_back(*++pair_it); // Larger value
		pend.push_back(*it->begin()); // Smaller value
	}

	// Insert the first element of S as it is the smallest
	S.push_front(pend.front());
	pend.pop_front();

	// Build the Jacobsthal sequence for efficient insertion
	std::list<int> jacob_sequence = build_jacob_insertion_sequence(pend.size());
	int comparisons = 0;

	// Insert elements from pend into S using Jacobsthal sequence
	for (std::list<int>::iterator it = jacob_sequence.begin(); it != jacob_sequence.end(); ++it) {
		std::list<int>::iterator pend_it = pend.begin();
		std::advance(pend_it, *it - 1);
		insert_into_sorted(S, *pend_it);
		pend.erase(pend_it);
		comparisons += 2; // Approximate comparisons
	}

	// Insert the remaining elements of pend
	for (std::list<int>::iterator it = pend.begin(); it != pend.end(); ++it) {
		insert_into_sorted(S, *it);
		comparisons += 2;
	}

	// Insert the straggler if present
	if (straggler != -1) {
		insert_into_sorted(S, straggler);
		comparisons += 2;
	}
	return S;
}

/* ---------------------------------------------------------- */











