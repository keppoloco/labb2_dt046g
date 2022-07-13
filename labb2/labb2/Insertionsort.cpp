#include "insertionsort.h"

void insertion_sort(std::vector<int>::iterator first, std::vector<int>::iterator last) {

	for (auto iter = first; iter != last; ++iter) {
		std::rotate(std::upper_bound(first, iter, *iter), iter, iter + 1);
	}
	assert(std::is_sorted(first, last));
}