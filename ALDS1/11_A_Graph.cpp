#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

void printMatrix(vector<vector<bool>> matrix) {
    for (auto p = matrix.begin(); p != matrix.end(); p++) {
        for (auto q = p->begin(); q != p->end(); q++) {
            if (q != p->begin()) cout << " ";
            cout << (*q ? 1 : 0);
        }
        cout << endl;
    }
}

int main() {
    int numVertex;

    cin >> numVertex;

    vector<vector<bool>> adjMatrix(numVertex, vector<bool>(numVertex, false));

    for (int i = 0; i < numVertex; i++) {
        int index, length;

        cin >> index >> length;
        for (int j = 0; j < length; j++) {
            int adjVertex;

            cin >> adjVertex;
            adjMatrix[index - 1][adjVertex - 1] = true;
        }
    }

    printMatrix(adjMatrix);

    return 0;
}