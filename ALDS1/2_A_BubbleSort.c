#include <stdio.h>

void scanArray(int *, int);
void printArray(int *, int);
int selectionSort(int *, int);

int main(void){
    int length;
    int array[100];

    scanf("%d", &length);
    scanArray(array, length);

    int exchangeCount = selectionSort(array, length);

    printArray(array, length);
    printf("%d\n", exchangeCount);
}

void scanArray(int *array, int length){
    int buf;

    for (int i = 0; i < length; i++){
        scanf("%d", &buf);
        array[i] = buf;
    }
}

void printArray(int *array, int length){
    for (int i = 0; i < length; i++){
        if (i != 0) printf(" ");
        printf("%d", array[i]);
    }
    printf("\n");
}

int selectionSort(int *array, int length){
    int buf;
    int flag = 1;
    int exchangeCount;

    while (flag){
        flag = 0;
        for (int i = 0; i < length-1; i++){
            if (array[i] > array[i+1]){
                buf = array[i];
                array[i] = array[i+1];
                array[i+1] = buf;
                exchangeCount++;
                flag = 1;
            }
        }
    }
    return exchangeCount;
}