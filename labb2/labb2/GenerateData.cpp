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
/*
void increasing_values(const unsigned int amount)
{
    increasingVector->reserve(amount);
    for (int i = 0; i < amount; i++) {
        int j = 1;
        increasingVector->emplace_back(j++);
    }
    return increasingVector;
}

void decreasing_values(const unsigned int amount)
{
    decreasingVector->reserve(amount);
    for (int i = 0; i < amount; i++) {
        int j = amount;
        decreasingVector->emplace_back(j--);
    }
    return decreasingVector;
}
*/
