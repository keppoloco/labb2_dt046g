#include "generatedata.h"
#include <time.h>

void random_values(std::vector<int>& data)
{
    srand(time(NULL));
    std::generate(data.begin(), data.end(), std::rand);
}

void constant_values(std::vector<int>& data)
{
    srand(1);
    int val = rand() % 100;
    std::generate(data.begin(), data.end(), [&val]() { return val; });
}

void increasing_values(std::vector<int>& data)
{
    int val = 1;
    for (std::vector<int>::iterator It = data.begin(); It != data.end(); It++) {
        *It = val++;
    }
}

void decreasing_values(std::vector<int>& data)
{
    int val = INT_MAX;
    for (std::vector<int>::iterator It = data.begin(); It != data.end(); It++) {
        *It = val--;
    }
}

