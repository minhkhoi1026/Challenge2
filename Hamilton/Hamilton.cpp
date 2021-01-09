#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef vector<vector<pair<int, int>>> adj_list;

/*---------UTILITIY FUNCTION---------*/

// Utility function to read input from given filename
adj_list readInputFile(const string filename) {
	ifstream in(filename);
	// number of vertex
	int n, u, v, w;
	in >> n;
	// read input to get adjacency list
	adj_list graph_list(n + 1);
	while (in >> u) {
		in >> v >> w;
		graph_list[u].push_back({ v, w });
		graph_list[v].push_back({ u, w });
	}
	in.close();
	return 	graph_list;
}

/*---------HAMILTONIAN CYCLE---------*/

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
	int n = graph_list.size() - 1;
	// create adjacency matrix from adjacency list
	vector<vector<bool>> graph_matrix(n + 1, vector<bool>(n + 1, false));
	for (int u = 1; u <= n; ++u) 
		for (pair<int, int> e : graph_list[u])
			graph_matrix[u][e.first] = true;
	vector<bool> visited(n + 1, false);
	return isHamiltonianCycle(1, 1, graph_list, graph_matrix, visited);
}

/*---------HAMILTONIAN PATH---------*/

// backtracking to get all cycle of graph, then check each of them
bool isHamiltonianPath(int u, int cnt, adj_list& graph_list,
	vector<vector<bool>>& graph_matrix, vector<bool>& visited) {
	visited[u] = true; // mark u as visited
	// size of graph, graph_list[0..n] so we need to substract 1
	int n = graph_list.size() - 1;

	// in the n-th vertex in path we return true
	if (cnt == n)
		return true;

	// backtracking
	for (pair<int, int> e : graph_list[u]) {
		int v = e.first;
		if (!visited[v]) { // have not been visited yet
			// if found one Hamiltonian Path then break, no need to found any more.
			if (isHamiltonianCycle(v, cnt + 1, graph_list, graph_matrix, visited))
				return true;
		}
	}
	visited[u] = false; // this section ended, mark u as not visited again
	return false;
}

// check if given graph (store in adjacency list graph_list)
// have Hamiltonian path
bool isHavingHamiltonianPath(adj_list& graph_list) {
	int n = graph_list.size() - 1;
	// create adjacency matrix from adjacency list
	vector<vector<bool>> graph_matrix(n + 1, vector<bool>(n + 1, false));
	for (int u = 1; u <= n; ++u)
		for (pair<int, int> e : graph_list[u])
			graph_matrix[u][e.first] = true;
	vector<bool> visited(n + 1, false);
	return isHamiltonianPath(1, 1, graph_list, graph_matrix, visited);
}

/*---------MAIN---------*/

int main() {
	string filename;
	cin >> filename;
	adj_list graph_list = readInputFile(filename);
	cout << "Have Hamiltonian Cycle: ";
	cout << int(isHavingHamiltonianCycle(graph_list)) << "\n";

	cout << "Have Hamiltonian Path: ";
	cout << int(isHavingHamiltonianPath(graph_list));
	return 0;
}