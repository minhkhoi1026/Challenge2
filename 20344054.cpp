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
	//Lowercase input to read some injection input like hPaTh or HpATh
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
adj_list readInputFile(const string filename) {
	ifstream in(filename);
	if (!in) {
		cerr << "Read Input Error!\n";
		adj_list empty_list;
		return empty_list;
	}
	// number of vertex
	int n=0, u, v, w;
	in >> n;
	if (n == 0) {
		cerr << "Read Empty File Error!\n";
		adj_list empty_list;
		return empty_list;
	}
	// read input to get adjacency list
	adj_list graph_list(n + 1);
	while (in >> u) {
		in >> v >> w;
		graph_list[u].push_back({ v, w });
		graph_list[v].push_back({ u, w });
	}
	in.close();
	return graph_list;
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
	adj_list graph_list = readInputFile(arg_path);
	if (graph_list.size() == 0) {
		cerr << "Can't read file at "<<arg_path<<'\n';
		return 2;
	}
	switch (resolveAction(arg_act))
	{
		case HPath: {
			if (isHavingHamiltonianPath(graph_list)) {
				cout << "Yes";
			}
			else {
				cout << "No";
			}
			break;
		}
		case HCycle: {
			if (isHavingHamiltonianCycle(graph_list)) {
				cout << "Yes";
			}
			else {
				cout << "No";
			}
			break;
		}
		case TSP: {
			pair<int, vector<int>> Res = TSPUsingBitmaskDP(graph_list);
			if (Res.first!=-1)
				for (auto u : Res.second) {
					cout << u << " ";
				}
			cout << '\n' << Res.first;
			break;
		}
		case Wrong_Action: {
			cerr << "Wrong action arguments!";
			return 3;
		}
	}
	return 0;
}