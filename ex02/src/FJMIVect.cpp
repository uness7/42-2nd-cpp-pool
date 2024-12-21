#include "FJMIVect.hpp"

FJMIVect::FJMIVect(void) {}
FJMIVect::~FJMIVect(void) {}
FJMIVect::FJMIVect(FJMIVect const &src) {
	(void) src;
}
FJMIVect& FJMIVect::operator=(FJMIVect const &src) {
	(void) src;
	return *this;
}

/* ------------------------------------------------------------- */

int	FJMIVect::jacobsthal(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

std::vector<int>	FJMIVect::build_jacob_insertion_sequence(int size) {
	std::vector<int> sequence;
	int index = 3; // Start at 3 as the first relevant Jacobsthal number

	while (jacobsthal(index) < size - 1) {
		sequence.push_back(jacobsthal(index));
		++index;
	}

	return sequence;
}

std::vector<std::vector<int> >	FJMIVect::create_pairs(std::vector<int> &array) {
	std::vector<std::vector<int> > pairs;
	std::vector<int> temp_pair;

	for (size_t i = 0; i < array.size(); ++i) {
		if (temp_pair.size() == 1) {
			temp_pair.push_back(array[i]);
			pairs.push_back(temp_pair);
			temp_pair.clear();
		} else if (pairs.size() * 2 == array.size() - 1) {
			pairs.push_back(std::vector<int>(1, array[i]));
		} else {
			temp_pair.push_back(array[i]);
		}
	}

	return pairs;
}

void	FJMIVect::sort_each_pair(std::vector<std::vector<int> > &pairs)
{
	for (size_t i = 0; i < pairs.size(); ++i) {
		if (pairs[i].size() == 2 && pairs[i][0] > pairs[i][1]) {
			std::swap(pairs[i][0], pairs[i][1]);
		}
	}
}

void	FJMIVect::insertion_sort_pairs(std::vector<std::vector<int> > &pairs) {
    for (size_t i = 1; i < pairs.size(); ++i) {
        std::vector<int> key = pairs[i];
        int j = i - 1;

        while (j >= 0 && pairs[j][1] > key[1]) {
            pairs[j + 1] = pairs[j];
            --j;
        }

        pairs[j + 1] = key;
    }
}

std::vector<int>	FJMIVect::create_s(
	std::vector<std::vector<int> > &pairs,
	int straggler)
{
	std::vector<int> S;
	std::vector<int> pend;

	int comparisons_made = 0;

	for (size_t i = 0; i < pairs.size(); ++i) {
		if (pairs[i].size() == 2) {
			S.push_back(pairs[i][1]);
			pend.push_back(pairs[i][0]);
		} else {
			S.push_back(pairs[i][0]);
		}
	}

	if (!pend.empty()) {
		S.insert(S.begin(), pend[0]);
		pend.erase(pend.begin());
	}

	std::vector<int> jacob_sequence = build_jacob_insertion_sequence(pend.size());

	size_t iterator = 0;
	while (iterator < pend.size()) {
		int item;
		if (!jacob_sequence.empty()) {
			item = pend[jacob_sequence[0] - 1];
			jacob_sequence.erase(jacob_sequence.begin());
		} else {
			item = pend[iterator++];
		}

		std::vector<int>::iterator insertion_point = std::lower_bound(S.begin(), S.end(), item);
		S.insert(insertion_point, item);
		comparisons_made += 2;
	}

	if (straggler != -1) {
		std::vector<int>::iterator insertion_point = std::lower_bound(S.begin(), S.end(), straggler);
		S.insert(insertion_point, straggler);
		comparisons_made += 2;
	}

	return S;
}

