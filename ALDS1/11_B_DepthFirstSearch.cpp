#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

struct vertex {
    vector<int> adjVertices;
    int discoveredTime = 0;
    int finishTime = 0;
};

int visit(vector<vertex> &adjList, int index, int time = 0) {
    adjList[index].discoveredTime = ++time;
    for (int i = 0; i < adjList[index].adjVertices.size(); i++) {
        int adjVertex = adjList[index].adjVertices[i];
        if (adjList[adjVertex].discoveredTime == 0) time = visit(adjList, adjVertex, time);
    }
    adjList[index].finishTime = ++time;

    return time;
}

void dfs(vector<vertex> &adjList) {
    int time = 0;
    for (int i = 0; i < adjList.size(); i++) {
        if (adjList[i].discoveredTime == 0) time = visit(adjList, i, time);
    }
}

int main() {
    int numVertex;
    cin >> numVertex;

    vector<vertex> adjList(numVertex);

    for (int i = 0; i < numVertex; i++) {
        int index, numAdjVertex;
        cin >> index >> numAdjVertex;

        for (int j = 0; j < numAdjVertex; j++) {
            int adjVertex;
            cin >> adjVertex;

            // 昇順になるように挿入
            for (auto p = adjList[index - 1].adjVertices.begin();; p++) {
                if (p == adjList[index - 1].adjVertices.end() || *p > adjVertex - 1) {
                    adjList[index - 1].adjVertices.insert(p, adjVertex - 1);
                    break;
                }
            }
        }
    }

    dfs(adjList);    

    for (int i = 0; i < numVertex; i++) {
        cout << i + 1 << " " << adjList[i].discoveredTime << " " << adjList[i].finishTime << endl;
    }

    return 0;
}
