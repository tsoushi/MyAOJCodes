#include <limits.h>
#include <iostream>
#include <vector>

int min(int a, int b) {
    if (a < b) return a;
    return b;
}

int matrixChainOrder(int *p, int length) {
    int n = length - 1;
    std::vector<std::vector<int>> m(n + 1, std::vector<int>(n + 1));

    for (int i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                m[i][j] = min(m[i][j], q);
            }
        }
    }

    return m[1][n];
}

int main() {
    int p[101];
    int n;

    std::cin >> n;

    for (int i = 0; i < n; i++) std::cin >> p[i] >> p[i + 1];

    std::cout << matrixChainOrder(p, n + 1) << std::endl;

    return 0;
}