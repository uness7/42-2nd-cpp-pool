# ifndef FJMIVECT_HPP
# define FJMIVECT_HPP

#include <iostream>
#include <vector>

class FJMIVect {
	public:
		FJMIVect();
		~FJMIVect();
		FJMIVect(FJMIVect const &src);
		FJMIVect &operator=(FJMIVect const &src);

		int				jacobsthal(int n);
		std::vector<int>		build_jacob_insertion_sequence(int size);
		std::vector<std::vector<int> >	create_pairs(std::vector<int> &array);
		void				sort_each_pair(std::vector<std::vector<int> > &pairs);
		void 				insertion_sort_pairs(std::vector<std::vector<int> > &pairs);
		std::vector<int> 		create_s(std::vector<std::vector<int> > &pairs, 
			int straggler);
};

# endif
