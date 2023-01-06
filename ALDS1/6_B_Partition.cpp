#include <iostream>

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
        }
    }
    swap<T>(A, i + 1, r);

    return i + 1;
}

int main() {
    int n;
    int A[100000];

    std::cin >> n;
    for (int i = 0; i < n; i++) std::cin >> A[i];

    int q = partition(A, 0, n - 1);

    for (int i = 0; i < n; i++) {
        if (i != 0) std::cout << " ";;
        if (i == q) std::cout << "[" << A[i] << "]";
        else std::cout << A[i];
    }
    std::cout << std::endl;

    return 0;
}