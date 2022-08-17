#include "selectionsort.h"


void selection_sort(std::vector<int>::iterator first, std::vector<int>::iterator last) {
	// find the min value between current iterator until the last
	// then we use std::iter_swap to swap the minimum value found with current iterator.
	// we then continue until we have reached the end of the vector
	// ex. [3, 1, 5, 2, 9] => [1, 3, 5, 2, 9] => [1, 2, 5, 3, 9] => [1, 2, 3, 5, 9]
	for (auto it = first; it != last; ++it) {
		auto min_value = std::min_element(it, last);
		std::iter_swap(min_value, it);
	}
	assert(std::is_sorted(first, last));
}