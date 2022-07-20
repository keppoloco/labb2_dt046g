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
	assert(std::is_sorted(leftIterator, rightIterator));

	// If last iteration, stop
	/*if (last - first < 2)
		return;
	//std::cout << "First: " << first - first << " Last: "  << last - first <<"\n";
	int pivot = *(first + std::distance(first, last - 1));
	// Capture pivot element, check element x vs pivot and if true element falls to the left, if false element falls to the right
	auto lower = std::partition(first, last, [pivot](int x) {return x < pivot; });
	auto higher = std::partition(first, last, [pivot](int x) {return !(x > pivot); });
	// Recursion - solving left side first then solve latest right side
	quick_sort(first, lower);
	quick_sort(higher, last);
	assert(std::is_sorted(first, last));*/
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
	assert(std::is_sorted(lower, higher));
}
