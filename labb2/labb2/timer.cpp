#include "timer.h"
const int INTERVALS = 10;

double time(void(*sort)(std::vector<int>::iterator, std::vector<int>::iterator), std::vector<int>* data)
{   
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < INTERVALS; i++) {
        sort(data->begin(), data->end());
    }
    auto stop = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
}

