#include "standardsort.h"

void standardsort(std::vector<int>::iterator first, std::vector<int>::iterator last) {
	std::sort(first, last);
	assert(std::is_sorted(first, last));
}