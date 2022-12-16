#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int count = 0;

void merge(int *A, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    int *L = malloc(sizeof(int) * (n1 + 1));
    int *R = malloc(sizeof(int) * (n2 + 1));

    for (int i = 0; i < n1; i++) L[i] = A[left + i];
    for (int i = 0; i < n2; i++) R[i] = A[mid + i];
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    int i = 0;
    int j = 0;
    for (int k = left; k < right; k++) {
        count++;
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }

    free(L);
    free(R);
}

void mergeSort(int *A, int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main() {
    int length;
    int array[500000];

    scanf("%d", &length);
    for (int i = 0; i < length; i++) scanf("%d", &array[i]);

    mergeSort(array, 0, length);

    for (int i = 0; i < length; i++) {
        if (i != 0) printf(" ");
        printf("%d", array[i]);
    }
    printf("\n");
    printf("%d\n", count);
}