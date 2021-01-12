#pragma once
#include "../Graph.h"

bool isHamiltonianCycle(int u, int cnt, adj_list& graph_list, adj_matrix& graph_matrix, vector<bool>& visited);
bool isHavingHamiltonianCycle(adj_list& graph_list);
bool isHamiltonianPath(int u, int cnt, adj_list& graph_list, adj_matrix& graph_matrix, vector<bool>& visited);
bool isHavingHamiltonianPath(adj_list& graph_list);
