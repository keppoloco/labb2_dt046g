#include "quicksort.h"
#include <cassert>

void quick_sort(std::vector<int>::iterator first, std::vector<int>::iterator last) {

	if (first >= last) {
		return;
	}

	auto pivot = *(first + std::distance(first, last - 1));
	auto leftIterator = std::partition(first, last, [pivot](const auto& elem) { return elem < pivot; });
	auto rightIterator = std::partition(first, last, [pivot](const auto& elem) { return !(elem > pivot); });

	quick_sort(first, leftIterator);
	quick_sort(rightIterator, last);
}

void quick_sort_median_three(std::vector<int>::iterator first, std::vector<int>::iterator last) {

	if (first == last) {
		return;
	}

	auto pivot = *std::next(first, std::distance(first, last) / 2);
	auto lower = std::partition(first, last, [pivot](const auto& elem) { return elem < pivot; });
	auto higher = std::partition(first, last, [pivot](const auto& elem) { return !(pivot < elem); });

	quick_sort_median_three(first, lower);
	quick_sort_median_three(higher, last);
}
