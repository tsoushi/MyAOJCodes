#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::string;

template<class T>
int LCSLength(vector<T> X, vector<T> Y) {
    int m = X.size();
    int n = Y.size();

    vector<vector<int>> c(m + 1, vector<int>(n + 1));

    for (int i = 1; i <= m; i++) c[i][0] = 0;
    for (int j = 1; j <= n; j++) c[0][j] = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) c[i][j] = c[i - 1][j - 1] + 1;
            else if (c[i - 1][j] >= c[i][j - 1]) c[i][j] = c[i - 1][j];
            else c[i][j] = c[i][j - 1];
        }
    }

    return c[m][n];
}

int main() {
    int n;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        string X;
        string Y;

        std::cin >> X >> Y;
        std::cout << LCSLength(vector<char>(X.begin(), X.end()), vector<char>(Y.begin(), Y.end())) << std::endl;
    }

    return 0;
}