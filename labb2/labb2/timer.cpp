#include "timer.h"

double time(void(*sort)(std::vector<int>::iterator, std::vector<int>::iterator), std::vector<int>& data)
{   
    auto start = std::chrono::high_resolution_clock::now();
    sort(data.begin(), data.end());
    auto stop = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
}

