#include "selectionsort.h"


void selection_sort(std::vector<int>::iterator first, std::vector<int>::iterator last) {
	for (; first != last; ++first) {
		auto min_value = std::min_element(first, last);
		std::iter_swap(min_value, first);
	}
	assert(std::is_sorted(first, last));
	/*const int size = dataset->size();

	for (int i = 0; i < size - 1; i++) {
		int m_index = i;
		for (int j = i + 1; j < size; j++) {
			if (dataset->at(j) < dataset->at(m_index)) {
				m_index = j;
			}
		}
		std::swap(dataset->at(m_index), dataset->at(i));
	}*/
}