#ifndef _UTILS_HPP
#define _UTILS_HPP

#include <algorithm>
#include <vector>
#include "data.hpp"

void processData(vector<DATA>&);

void findMeanAndMultiplyBy2(vector<DATA>& V);

DATA findSumEqualTo(vector<DATA>& V, int N);

#endif
