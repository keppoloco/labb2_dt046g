#include "selectionsort.h"


void selection_sort(std::vector<int>::iterator first, std::vector<int>::iterator last) {
	for (auto it = first; it != last; ++it) {
		auto min_value = std::min_element(it, last);
		std::iter_swap(min_value, it);
	}
	assert(std::is_sorted(first, last));
}