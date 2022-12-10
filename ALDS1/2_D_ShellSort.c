#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *, int, int);
void shellSort(int *, int);
void printArray(int *, int, char *);
void printArrayReverse(int *, int, char *);

int cnt;

int main() {
    int length;
    int *array; // スタック領域で巨大な配列(1000000要素数)を確保すると、実行時にエラーが発生した

    scanf("%d", &length);
    array = (int*)malloc(sizeof(int) * length); // 長さlengthのint配列を確保
    // 配列読み込み
    for (int i = 0; i < length; i++) {
        scanf("%d", &array[i]);
    }

    shellSort(array, length);
    printf("%d\n", cnt);
    printArray(array, length, "\n");
}

void insertionSort(int *array, int length, int step) {
    for (int i = step; i < length; i++) {
        int buf = array[i];
        int j = i - step;

        while (j >= 0 && array[j] > buf) {
            array[j + step] = array[j];
            j -= step;
            cnt++;
        }
        array[j + step] = buf;
    }
}

void shellSort(int *array, int length) {
    int G[100];
    int m;

    cnt = 0;
    G[0] = 1;

    for (int i = 1; i < 100; i++) {
        if (3 * G[i - 1] + 1 < length) {
            G[i] = 3 * G[i - 1] + 1;
        } else {
            m = i;
            break;
        }
    }
    
    printf("%d\n", m); // 整数m
    printArrayReverse(G, m, " "); // m個の整数G

    for (int i = m - 1; i >= 0; i--) {
        insertionSort(array, length, G[i]);
    }
}

/*
配列を標準出力する
引数
    array: 配列へのポインタ
    lenght: 配列の長さ
    separator: 要素どうしの間に入れる文字列（空白など）
*/ 
void printArray(int *array, int length, char *separator) {
    for (int i = 0; i < length; i++) {
        if (i != 0) printf("%s", separator);
        printf("%d", array[i]);
    }
    printf("\n");
}

void printArrayReverse(int *array, int length, char *separator) {
    for (int i = length - 1; i >= 0; i--) {
        if (i != length - 1) printf("%s", separator);
        printf("%d", array[i]);
    }
    printf("\n");
}