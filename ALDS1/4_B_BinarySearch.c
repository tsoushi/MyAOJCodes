#include <stdio.h>

int binarySearch(int *array, int length, int key) {
    int left = 0;
    int right = length;

    while (left < right) {
        int mid = (left + right) / 2;

        if (array[mid] == key) return 1;
        else if (key < array[mid]) right = mid;
        else left = mid + 1;
    }

    return 0;
}

int main() {
    int S[100001];
    int T[50000];
    int lenS, lenT;

    scanf("%d", &lenS);
    for (int i = 0; i < lenS; i++) scanf("%d", &S[i]);

    scanf("%d", &lenT);
    for (int i = 0; i < lenT; i++) scanf("%d", &T[i]);

    // 探索
    int foundCount = 0;
    for (int i = 0; i < lenT; i++) {
        if (binarySearch(S, lenS, T[i]) == 1) foundCount++;
    }

    printf("%d\n", foundCount);

    return 0;
}
