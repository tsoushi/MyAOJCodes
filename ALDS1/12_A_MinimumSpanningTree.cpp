#include <iostream>
#include <vector>
#include <limits>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::numeric_limits;


int prim(vector<vector<int>> weight, int root) {
    int num = weight.size();
    vector<int> minCosts(num, numeric_limits<int>::max());
    vector<int> parent(num, -1);
    vector<int> state(num, 0);

    minCosts[root] = 0;

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

            if (state[i] != 2 && weight[u][i] < minCosts[i]) {
                parent[i] = u;
                minCosts[i] = weight[u][i];
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < num; i++) {
        if (parent[i] != -1) sum += weight[i][parent[i]];
    }

    return sum;
}

int main() {
    int num;
    cin >> num;

    vector<vector<int>> weight(num, vector<int>(num));

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            cin >> weight[i][j];
            //if (weight[i][j] == -1) weight[i][j] = numeric_limits<int>::max();
        }
    }

    cout << prim(weight, 0) << endl;
}