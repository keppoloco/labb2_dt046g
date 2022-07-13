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

const int SIZE = 300;
const int REPETITIONS = 10;
const int SAMPLES = 20;

double timeIt(void(*sort)(std::vector<int>::iterator, std::vector<int>::iterator), std::vector<int> data);

int main() {
	std::vector<int> data;
	std::vector<int> copy;
	std::vector<double> period(SAMPLES);

	

	std::string file[] = { "standard_sort.data", "insertion_sort_rand.data", "selection_sort.data", "quick_sort_rp.data", "quick_sort_med.data" };
	std::ofstream os;
	os.open(file[1], std::ios::out | std::ios::app);

	if (os.is_open())
	{
		os << "N\t" << "T[ms]\t" << "dev[ms]\t" << "Samples\n";
		int increment = 0;
		for (int iter = 1; iter <= REPETITIONS; iter++)
		{
			increment++;
			data.resize(SIZE * increment);
			random_values(data);

			for (int i = 0; i < SAMPLES; i++) 
			{
				// Copy dataset
				copy = data;
				// run it
				period[i] = time(&insertion_sort, copy);
			}
			os << SIZE * increment << "\t" << average_value(period) << "\t" << std_dev(period) << "\t" << SAMPLES << '\n';
		}
		os.close();
	}

	for (auto it = copy.begin(); it != copy.end(); it++) {
		std::cout << *it << '\n';
	}

	return 0;
}

double timeIt(void(*sort)(std::vector<int>::iterator, std::vector<int>::iterator), std::vector<int> data)
{
	auto start = std::chrono::high_resolution_clock::now();
	sort(data.begin(), data.end());
	auto stop = std::chrono::high_resolution_clock::now();

	return std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
}