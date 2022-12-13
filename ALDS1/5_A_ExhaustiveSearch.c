#include <stdio.h>

int solve(int *array, int length, int i, int m) {
    if (m == 0) return 1;
    if (i >= length) return 0;
    return solve(array, length, i + 1, m) || solve(array, length, i + 1, m - array[i]);
}

int main() {
    int n, q;
    int A[20];
    int m[200];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);
    scanf("%d", &q);
    for (int i = 0; i < q; i++) scanf("%d", &m[i]);

    for (int i = 0; i < q; i++) {
        printf(solve(A, n, 0, m[i]) ? "yes\n" : "no\n");
    }

    return 0;
}