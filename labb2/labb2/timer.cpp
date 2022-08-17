#include "timer.h"

double time(void(*sort)(std::vector<int>::iterator, std::vector<int>::iterator), std::vector<int>::iterator first, std::vector<int>::iterator last)
{   
    auto start = std::chrono::high_resolution_clock::now();
    sort(first, last);
    auto stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> total = (stop - start);
    return total.count();
}

