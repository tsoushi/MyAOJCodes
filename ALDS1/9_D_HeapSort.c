#include <stdio.h>
void print(int *array, int N) {
    for (int i = 1; i <= N; i++) {
        if (i != 1) printf(" ");
        printf("%d", array[i]);
    }
    printf("\n");
}
void maxHeapify(int *tree, int root, int length) {
    int leftIndex = root * 2;
    int rightIndex = root * 2 + 1;
    int largestIndex;

    if (leftIndex <= length && tree[leftIndex] > tree[root]) largestIndex = leftIndex;
    else largestIndex = root;
    if (rightIndex <= length && tree[rightIndex] > tree[largestIndex]) largestIndex = rightIndex;

    if (largestIndex != root) {
        // swap
        int buf = tree[root];
        tree[root] = tree[largestIndex];
        tree[largestIndex] = buf;
        maxHeapify(tree, largestIndex, length);
    }
}

void heapSort(int *array, int length) {
    for (int i = length / 2; i >= 1; i--) maxHeapify(array, i, length);

    int heapSize = length;
    while (heapSize >= 2) {
        // swap
        int buf = array[1];
        array[1] = array[heapSize];
        array[heapSize] = buf;

        heapSize--;
        maxHeapify(array, 1, heapSize);
    }
}

int parent(int i) {
    return i / 2;
}

int main() {
    int N;
    int array[200000];

    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%d", &array[i]);

    heapSort(array, N);

    for (int i = 2; i < N; i++) {
        int index = i;

        while (parent(index) > 1) {
            // swap
            int buf = array[index];
            array[index] = array[parent(index)];
            array[parent(index)] = buf;
            index = parent(index);
        }
    }

    // swap
    int buf = array[1];
    array[1] = array[N];
    array[N] = buf;

    for (int i = 1; i <= N; i++) {
        if (i != 1) printf(" ");
        printf("%d", array[i]);
    }
    printf("\n");

    return 0;
}