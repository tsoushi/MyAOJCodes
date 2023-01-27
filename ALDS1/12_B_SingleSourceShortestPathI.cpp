#include <iostream>
#include <vector>
#include <limits>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::numeric_limits;


vector<int> dijkstra(vector<vector<int>> weight, int root) {
    int num = weight.size();
    vector<int> minCosts(num, numeric_limits<int>::max());
    vector<int> parent(num, -1);
    vector<int> state(num, 0);

    minCosts[root] = 0;
    state[0] = 1;

    while (true) {
        int minCost = numeric_limits<int>::max();
        int u;
        
        for (int i = 0; i < num; i++) {
            if (state[i] != 2 && minCosts[i] < minCost) {
                minCost = minCosts[i];
                u = i;
            }
        }

        if (minCost == numeric_limits<int>::max()) break;

        state[u] = 2;

        for (int i = 0; i < num; i++) {
            if (weight[u][i] == -1) continue;

            if (state[i] != 2 && minCosts[u] + weight[u][i] < minCosts[i]) {
                minCosts[i] = minCosts[u] + weight[u][i];
                state[i] = 1;
            }
        }
    }

    return minCosts;
}

int main() {
    int num;
    cin >> num;

    vector<vector<int>> weight(num, vector<int>(num, -1));

    for (int i = 0; i < num; i++) {
        int index, numAdj;
        cin >> index >> numAdj;

        for (int j = 0; j < numAdj; j++) {
            int adjIndex;
            cin >> adjIndex;
            cin >> weight[index][adjIndex];
        }
    }

    vector<int> minCosts = dijkstra(weight, 0);
    
    for (int i = 0; i < num; i++) {
        cout << i << " " << minCosts[i] << endl;
    }

    return 0;
}