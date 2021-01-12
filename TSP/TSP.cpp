#include "TSP.h"

/*---------TSP Using Dynamic Programing---------*/
/*
// backtracking to get all cycle of graph, then check each of them
bool isHamiltonianCycle(int u, int cnt, adj_list& graph_list,
	vector<vector<bool>>& graph_matrix, vector<bool>& visited) {
	visited[u] = true; // mark u as visited
	// size of graph, graph_list[0..n] so we need to substract 1
	int n = graph_list.size() - 1;

	// in the n-th vertex in path we just have to check
	// if therre is a edge from n-th vertex in path to 1
	if (cnt == n)
		return graph_matrix[u][1];

	// backtracking
	for (pair<int, int> e : graph_list[u]) {
		int v = e.first;
		if (!visited[v]) { // have not been visited yet
			// if found one Hamiltonian Cycle then break, no need to found any more.
			if (isHamiltonianCycle(v, cnt + 1, graph_list, graph_matrix, visited))
				return true;
		}
	}
	visited[u] = false; // this section ended, mark u as not visited again
	return false;
}

// check if given graph (store in adjacency list graph_list)
// have Hamiltonian cycle
bool isHavingHamiltonianCycle(adj_list& graph_list) {
	int n = graph_list.size() - 1;
	// create adjacency matrix from adjacency list
	vector<vector<bool>> graph_matrix(n + 1, vector<bool>(n + 1, false));
	for (int u = 1; u <= n; ++u)
		for (pair<int, int> e : graph_list[u])
			graph_matrix[u][e.first] = true;
	vector<bool> visited(n + 1, false);
	return isHamiltonianCycle(1, 1, graph_list, graph_matrix, visited);
}

*/