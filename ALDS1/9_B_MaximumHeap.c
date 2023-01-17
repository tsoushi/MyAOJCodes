#include <stdio.h>

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

void buildMaxHeap(int *tree, int length) {
    for (int i = length / 2; i >= 1; i--) maxHeapify(tree, i, length);
}

int main() {
    int H;
    int tree[500001];

    // input
    scanf("%d", &H);
    for (int i = 1; i <= H; i++) scanf("%d", &tree[i]);

    buildMaxHeap(tree, H);

    // output
    for (int i = 1; i<= H; i++) printf(" %d", tree[i]);
    printf("\n");

    return 0;
}
