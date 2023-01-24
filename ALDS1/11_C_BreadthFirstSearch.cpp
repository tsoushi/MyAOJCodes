#include <iostream>
#include <vector>
#include <queue>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::queue;

struct vertex {
    vector<int> adjVertices;
    int distance = -1;
    int state = 0;
};

void bfs(vector<vertex> &adjList) {
    queue<int> q;

    adjList[0].state = 1;
    adjList[0].distance = 0;
    q.push(0);
    while (!q.empty()) {
        int index = q.front();
        q.pop();

        for (auto p = adjList[index].adjVertices.begin(); p != adjList[index].adjVertices.end(); p++) {
            if (adjList[*p].state == 0) {
                adjList[*p].state = 1;
                adjList[*p].distance = adjList[index].distance + 1;
                q.push(*p);
            }
            adjList[index].state = 2;
        }
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

    bfs(adjList);    

    for (int i = 0; i < numVertex; i++) {
        cout << i + 1 << " " << adjList[i].distance << endl;
    }

    return 0;
}
