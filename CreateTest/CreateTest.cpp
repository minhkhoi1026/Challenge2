#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <chrono>
#include "../Graph.h"
#include <random>
#include <assert.h> 
using namespace std;

// Tên chương trình
const string NAME = "TSP";
// Số test kiểm tra
const int NTEST = 100;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long Rand(long long l, long long h) {
    assert(l <= h);
    return l + rand() * 1LL * rand() % (h - l + 1);
}

int main()
{
    srand(time(NULL));
    for (int iTest = 1; iTest <= NTEST; iTest++)
    {
        ofstream inp("Graph.txt");
        int n = Rand(10, 12);
        inp << n << '\n';
        adj_matrix graph_matrix(n+1,vector<int> (n+1,0));
        for (int i = 1; i <= n; i++) 
        for (int j = i + 1; j <= n; j++) {
            if (Rand(0, 2) == 0) continue;
            graph_matrix[i][j] = graph_matrix[j][i] = Rand(1, 10);
        }
        adj_list graph_list = ConvertToAdjList(graph_matrix);
        for (int i = 0; i < n; i++) {
            for (auto u : graph_list[i]) {
                if (i > u.first) continue;
                inp << i << " " << u.first << " " << u.second << '\n';
            }
        }
        inp.close();
        system((NAME + ".exe TSP Graph.txt").c_str());
        system((NAME + "_trau.exe").c_str());
        if (system("fc TSP.txt output_trau.txt") != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}