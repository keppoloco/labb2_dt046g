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
const int SAMPLES = 10;

double timeIt(void(*sort)(std::vector<int>::iterator, std::vector<int>::iterator), std::vector<int> data);

int main() {
	std::vector<int> data;
	std::vector<int> copy;
	std::vector<double> period(SAMPLES);

	std::string file[] = { "standard_sort_dec.data", "insertion_sort_rand.data", "selection_sort_dec.data", "quick_sort_rp_const.data", "quick_sort_med_rand.data" };
	std::ofstream os;
	os.open(file[2], std::ios::out | std::ios::app);

	if (os.is_open())
	{
		os << "N\t" << "T[ms]\t" << "dev[ms]\t" << "Samples\n";
		int increment = 0;
		for (int iter = 1; iter <= REPETITIONS; iter++)
		{
			increment++;
			data.resize(SIZE * increment);
			decreasing_values(data);

			for (int i = 0; i < SAMPLES; i++) 
			{
				// Copy dataset
				copy = data;
				// run it
				period[i] = time(&selection_sort, copy.begin(), copy.end());
			}
			os << SIZE * increment << "\t" << average_value(period) << "\t" << std_dev(period) << "\t" << SAMPLES << '\n';
		}
		os.close();
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