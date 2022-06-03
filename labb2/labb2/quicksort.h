#pragma once
#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <algorithm>
#include <vector>

void quick_sort(std::vector<int>::iterator first, std::vector<int>::iterator last);
void quick_sort_median_three(std::vector<int>::iterator first, std::vector<int>::iterator last);

#endif // !QUICKSORT_H
