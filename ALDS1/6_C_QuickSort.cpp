#include <iostream>

struct Card {
    char pattern;
    int num;
    int dupCount = 0; // numが重複した場合の連番
    bool operator<=(const Card right) {
        return num <= right.num;
    }
    bool operator==(const Card right) {
        return num == right.num && pattern == right.pattern;
    }
};

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

template <class T>
void quickSort(T *A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}

template <class T>
bool isStable(T *array, int length) {
    for (int i = 1; i < length; i++) {
        for (int j = 0; j < i; j++) {
            if (array[j].num == array[i].num && array[j].dupCount > array[i].dupCount) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int n;
    Card array[100000];

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> array[i].pattern >> array[i].num;
        for (int j = 0; j < i; j++) {
            if (array[i].num == array[j].num) {
                array[i].dupCount++;
                break;
            }
        }
    }

    quickSort(array, 0, n - 1);
    
    if (isStable(array, n)) std::cout << "Stable" << std::endl;
    else std::cout << "Not stable" << std::endl;

    for (int i = 0; i < n; i++) {
        std::cout << array[i].pattern << " " << array[i].num << std::endl;
    }

    return 0;
}