#include "Hamilton.h"

/*---------HAMILTONIAN CYCLE---------*/

// backtracking to get all cycle of graph, then check each of them
bool isHamiltonianCycle(int u, int cnt, adj_list& graph_list,
	adj_matrix& graph_matrix, vector<bool>& visited) {
	// size of graph, graph_list[0..n] so we need to substract 1
	int n = graph_list.size() - 1;

	// in the n-th vertex in path we just have to check
	// if therre is a edge from n-th vertex in path to 1
	if (cnt == n) {
		return ((graph_matrix[u][1] > 0) ? true : false);
	}
	visited[u] = true; // mark u as visited
	// backtracking
	for (pair<int,int> e: graph_list[u]) {
		int v = e.first;
		if (!visited[v]) { // have not been visited yet
			// if found one Hamiltonian Cycle then break, no need to found any more.
			if(isHamiltonianCycle(v, cnt + 1, graph_list, graph_matrix, visited))
				return true; 
		}	
	}
	visited[u] = false; // this section ended, mark u as not visited again
	return false;
}

// check if given graph (store in adjacency list graph_list)
// have Hamiltonian cycle
bool isHavingHamiltonianCycle(adj_list& graph_list) {
	vector<bool> visited(graph_list.size(), false);
	adj_matrix graph_matrix = ConvertToAdjMatrix(graph_list);
	return isHamiltonianCycle(1, 1, graph_list, graph_matrix, visited);
}

/*---------HAMILTONIAN PATH---------*/

// backtracking to get all cycle of graph, then check each of them
bool isHamiltonianPath(int u, int cnt, adj_list& graph_list,
	adj_matrix& graph_matrix, vector<bool>& visited) {
	// size of graph, graph_list[0..n] so we need to substract 1
	int n = graph_list.size() - 1;

	// in the n-th vertex in path we return true
	if (cnt == n)
		return true;
	visited[u] = true; // mark u as visited
	// backtracking
	for (pair<int, int> e : graph_list[u]) {
		int v = e.first;
		if (!visited[v]) { // have not been visited yet
			// if found one Hamiltonian Path then break, no need to found any more.
			if (isHamiltonianPath(v, cnt + 1, graph_list, graph_matrix, visited))
				return true;
		}
	}
	visited[u] = false; // this section ended, mark u as not visited again
	return false;
}

// check if given graph (store in adjacency list graph_list)
// have Hamiltonian path
bool isHavingHamiltonianPath(adj_list& graph_list) {
	vector<bool> visited(graph_list.size(), false);
	adj_matrix graph_matrix = ConvertToAdjMatrix(graph_list);
	return isHamiltonianPath(1, 1, graph_list, graph_matrix, visited);
}
