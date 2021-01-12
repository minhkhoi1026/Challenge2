#pragma once
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef vector<vector<ii>> adj_list;
typedef vector<vector<int>> adj_matrix;

adj_matrix ConvertToAdjMatrix(const adj_list&);
adj_list ConvertToAdjList(const adj_matrix&);