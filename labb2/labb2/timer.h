#pragma once
#ifndef TIMER_H
#define TIMER_H
#include <chrono>
#include <algorithm>
#include <vector>

double time(void(*sort)(std::vector<int>::iterator, std::vector<int>::iterator), std::vector<int> *data);

#endif