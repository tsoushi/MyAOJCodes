#include <iostream>

int cost = 0;

template <class T>
void swap(T *array, int i1, int i2) {
    T buf = array[i2];
    array[i2] = array[i1];
    array[i1] = buf;
}

template <class T>
int partition(T *A, int p, int r) {
    T x = A[r];
    int i = p - 1;

    for (int j = p; j < r; j++) {
        if (A[j] <= x) {
            i++;
            swap<T>(A, i, j);
            cost += A[i] + A[j];
        }
    }
    swap<T>(A, i + 1, r);
    cost += A[i + 1] + A[r];

    return i + 1;
}

template <class T>
void quickSort(T *A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}

int main() {
    int n;
    int array[1000];

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }

    quickSort(array, 0, n - 1);
    
    std::cout << cost << std::endl;

    return 0;
}