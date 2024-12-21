#ifndef FJMILIST_HPP
#define FJMILIST_HPP

#include <iostream>
#include <list>
#include <algorithm>

class FJMIList {
	public:
		FJMIList(void);
		~FJMIList(void);
		FJMIList(FJMIList const &src);
		FJMIList &operator=(FJMIList const &src);

		/* Member functions */
		int
		jacobstha(int n);

		std::list<std::list<int> >
		create_pairs(std::list<int> &input);
		
		void
		sort_each_pair(std::list<std::list<int> > &pairs);

		void
		insert_into_sorted(std::list<int> &sorted, int value);
		
		void
		insertion_sort_pairs(std::list<std::list<int> > &pairs);
		
		std::list<int>
		build_jacob_insertion_sequence(int size);
		
		std::list<int>
		create_s(std::list<std::list<int> > &pairs, int stragller);
};

#endif
