#include "insertionsort.h"

void insertion_sort(std::vector<int>::iterator first, std::vector<int>::iterator last) {
	// upper_bound returns iterator pointing to greater element
	// then we rotate elements to the left, ex. => 0 5 3 => 5 0 3 => 5 3 0
	// until sorted
	for (auto iter = first; iter != last; ++iter) {
		std::rotate(std::upper_bound(first, iter, *iter), iter, iter + 1);
	}
	assert(std::is_sorted(first, last));
}