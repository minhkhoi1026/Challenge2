#include "Hamilton/Hamilton.h"
#include "TSP/TSP.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

/*---------RESOLVE ACTION FUNCTION---------*/
enum Action {
	HPath,
	HCycle,
	TSP,
	Wrong_Action
};

Action resolveAction(string input) {
	for (auto& c : input)
	{
		c = tolower(c);
	}
	if (input == "hpath") return HPath;
	if (input == "hcycle") return HCycle;
	if (input == "tsp") return TSP;
	return Wrong_Action;
}
/*-----------------------------------------*/

/*---------IN-OUT FUNCTION---------*/

// Utility function to read input from given filename
pair<int,adj_list> readInputFile(const string filename) {
	ifstream in(filename);
	if (!in) {
		cerr << "Read Input Error!";
		adj_list empty_list;
		return make_pair(-1,empty_list);
	}
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
	return make_pair(n,graph_list);
}


int main(int argc, char* argv[])
{
	if (argc < 3) {
		cerr << "Not enough arguments!";
		return 1;
	}
	string arg_act, arg_path;
	arg_act += argv[1];
	for (int i = 2; i < argc; i++) {
		arg_path += argv[i];
		arg_path += " ";
	}
	arg_path.pop_back();
	int n;
	adj_list graph_list;
	pair<int, adj_list> input = readInputFile(arg_path);
	if (input.first == -1) {
		cerr << "Can't read file at "<<arg_path<<'\n';
		return 2;
	}
	n = input.first;
	graph_list = input.second;
	switch (resolveAction(arg_act))
	{
		case HPath: {
			isHavingHamiltonianPath(graph_list);
			break;
		}
		case HCycle: {
			isHavingHamiltonianCycle(graph_list);
			break;
		}
		case TSP: {
			// Code Later
			break;
		}
		case Wrong_Action: {
			cerr << "Wrong action arguments!";
			return 3;
		}
	}

	return 0;
}