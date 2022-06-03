#pragma once
#ifndef GENERATEDATA_H
#define GENERATEDATA_H
#include <vector>
#include <algorithm>
#include <random>

void random_values(std::vector<int>& data);
void increasing_values(std::vector<int>& data);
void decreasing_values(std::vector<int>& data);
void constant_values(std::vector<int>& data);

#endif
