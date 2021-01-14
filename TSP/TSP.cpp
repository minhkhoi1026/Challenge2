#include "TSP.h"
/*---------TSP Using Dynamic Programing---------*/
int SizeofState(int state, int numstate) { //Number of bit 1 in a bitmask ( 101001 = 3 || 1100 = 2)
    int size = 0;
    for (int i = 0; i < log2(numstate + 1); i++) {
        if (((state & (1 << i)) >> i) == 1) size++;
    }
    return size;
}

bool CheckBit(int state, int bit) { //Check bit'th is 1 or 0    
    bit--;
    return ((state) & (1 << (bit)));
}

int OffBit(int state, int bit) { //Change bit'th from 1 to 0 or return 0
    if(bit <= 0) return state;
    return (state & ~(1 << (bit - 1)));
}

pair<int,vector<int>> TSPUsingBitmaskDP(adj_list& graph_list) { //Solve Travelling Salesman Problems With Bitmask Dynamic Programing. Complexity O(n^2*2^n)
    adj_matrix graph_matrix = ConvertToAdjMatrix(graph_list);
    int n = graph_list.size() - 1;
    int numstate = (1 << n) - 1;
    vector<vector<int>> State(numstate+1, vector<int>(graph_list.size()+1, INTMAX)); // Create A DP Array with numstate is the number of state when using bitmask
    vector<vector<int>> Parent(numstate+1, vector<int>(graph_list.size()+1, 1));
    for (int i = 2; i <= numstate; i++) {
        if ((i & 1) == 0) continue;
        if (SizeofState(i, numstate) == 2) { //If only have 2 edge -> 1 - i | Always start at 1
            for (int j = 2; j <= n; j++) {
                if (CheckBit(i,j) && graph_matrix[1][j] != 0){
                    State[i][j] = graph_matrix[1][j]; //Set state 10.1 end at bit 
                }
            }
        }
        else {
            if (SizeofState(i, numstate) > 2) { //If 
                for (int j = 2; j <= n; j++) {
                    if (CheckBit(i, j))
                    for (int k = 2; k <= n; k++){
                        if (j == k) continue;
                        if (CheckBit(i, k) && graph_matrix[k][j] != 0 ) {
                            if (State[i][j] >= (State[OffBit(i,j)][k] + graph_matrix[k][j])) {
                                State[i][j] = State[OffBit(i,j)][k] + graph_matrix[k][j];
                                Parent[i][j] = k;
                            }
                        }
                    }
                }
            }
        }
    }
    int MinVal = INTMAX;
    int MinIndex;
    for (int i = 2; i <= n; i++) {
        if (graph_matrix[i][1]!=0)
            if (State[numstate][i] + graph_matrix[i][1] < MinVal) {
                MinVal = State[numstate][i] + graph_matrix[i][1];
                MinIndex = i;
            }
    }
    vector<int> Res;
    Res.push_back(1);
    Res.push_back(MinIndex);
    while (MinIndex != 1) {
        int old_index = MinIndex;
        MinIndex = Parent[numstate][MinIndex];
        numstate = OffBit(numstate, old_index);
        Res.push_back(MinIndex);
    }
    Res.pop_back();
    if (MinVal == INTMAX) MinVal = -1;
    return make_pair(MinVal,Res);
}
/*----------------------------------------------*/
