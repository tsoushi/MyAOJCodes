#include <stdio.h>

void swapInt(int *array, int i1, int i2) {
    int buf = array[i2];
    array[i2] = array[i1];
    array[i1] = buf;
}

int partition(int *A, int p, int r) {
    int x = A[r];
    int i = p - 1;

    for (int j = p; j < r; j++) {
        if (A[j] <= x) {
            i++;
            swapInt(A, i, j);
        }
    }
    swapInt(A, i + 1, r);

    return i + 1;
}

int main() {
    int n;
    int A[100000];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);

    int q = partition(A, 0, n - 1);

    for (int i = 0; i < n; i++) {
        if (i != 0) printf(" ");
        if (i == q) printf("[%d]", A[i]);
        else printf("%d", A[i]);
    }
    printf("\n");

    return 0;
}