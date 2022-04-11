#include "selectionsort.h"

void selection_sort(std::vector<float>* dataset) {
	const int size = dataset->size();

	for (int i = 0; i < size - 1; i++) {
		int m_index = i;
		for (int j = i + 1; j < size; j++) {
			if (dataset->at(j) < dataset->at(m_index)) {
				m_index = j;
			}
		}
		std::swap(dataset->at(m_index), dataset->at(i));
	}
}