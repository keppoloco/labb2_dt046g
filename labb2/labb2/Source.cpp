#include <iostream>
#include <time.h>
#include "quicksort.h"
#include "selectionsort.h"
#include "insertionsort.h"
#include "standardsort.h"
#include "measurement.h"
#include "timer.h"
#include <fstream>
#include "generatedata.h"

const int DATASET = 300;
const int REPETITIONS = 15;

int main() {
	std::string files[] = { "standard_sort.txt", "insertion_sort.txt", "selection_sort.data", "quick_sort_rp.txt", "quick_sort_med.txt", "sort.txt" };
	std::vector<int> data;
	std::vector<int>* copy = nullptr;
	
	std::ofstream os;

	os.open(files[0], std::ios::out | std::ios::app);
	if (os.is_open()) {
		os << "N\t" << "T[ms]\t" << "dev[ms]\t" << "Samples\n";
		std::vector<double> period;
		period.resize(REPETITIONS);

		for (int i = 1; i <= REPETITIONS; i++) {
			data.resize(DATASET * i);
			random_values(data);
 			copy = &data;
			period[i-1] = (time(standardsort, copy));

			os << DATASET * i << "\t" << average_value(period) << "\t" << std_dev(period) << "\t" << REPETITIONS << '\n';
		}
	}
	os.close();

	for (auto it = copy->begin(); it != copy->end(); it++) {
		std::cout << *it << '\n';
	}

	return 0;
}