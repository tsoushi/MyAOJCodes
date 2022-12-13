#include <stdio.h>

int linearSearch(int *array, int length, int key) {
    int i = 0;

    array[length] = key;

    while (array[i] != key) i++;

    if (i == length) return 0;
    else return 1;
}

int main() {
    int S[10001];
    int T[500];
    int lenS, lenT;

    scanf("%d", &lenS);
    for (int i = 0; i < lenS; i++) scanf("%d", &S[i]);

    scanf("%d", &lenT);
    for (int i = 0; i < lenT; i++) scanf("%d", &T[i]);

    // 探索
    int foundCount = 0;
    for (int i = 0; i < lenT; i++) {
        if (linearSearch(S, lenS, T[i])) foundCount++;
    }

    printf("%d\n", foundCount);

    return 0;
}
