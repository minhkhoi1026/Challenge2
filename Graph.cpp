#include "Graph.h"

//Only Use With Undirected Graph

// create adjacency matrix from adjacency list
adj_matrix ConvertToAdjMatrix(const adj_list& input)
{
	int n = input.size() - 1;
	adj_matrix output(n + 1, vector<int>(n + 1, 0));
	for (int u = 1; u <= n; ++u)
		for (pair<int, int> e : input[u]) {
			output[u][e.first] = e.second;
		}
    return output;
}

// create adjacency list from adjacency matrix
adj_list ConvertToAdjList(const adj_matrix& input)
{
	int n = input.size() - 1;
	adj_list output(n + 1);
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++) {
			if (input[i][j] > 0) {
				output[i].push_back(make_pair(j, input[i][j]));
				output[j].push_back(make_pair(i, input[i][j]));
			}
		}
	return output;
}
