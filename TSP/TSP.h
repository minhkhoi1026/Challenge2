#pragma once

#include "../Graph.h"
#define INTMAX 1000000007
int SizeofState(int state, int numstate);
pair<int, vector<int>> TSPUsingBitmaskDP(adj_list& graph_list);
