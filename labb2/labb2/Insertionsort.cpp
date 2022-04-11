#include "insertionsort.h"

void insertion_sort(std::vector<float>* dataset) {
	const int size = dataset->size();

	for (int i = 1; i < size; i++) {
		float key = dataset->at(i);
		int index = i - 1;

		while (index >= 0 && dataset->at(index) > key) {
			dataset->at(index + 1) = dataset->at(index);
			index -= 1;
		}
		dataset->at(index + 1) = key;
	}
}