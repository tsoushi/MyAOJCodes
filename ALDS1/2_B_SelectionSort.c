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
    int exchangeCount = 0;

    for(int i = 0; i < length; i++){
        int minIndex = i;
        for (int j = i; j < length; j++){
            if (array[j] < array[minIndex]){
                minIndex = j;
            }
        }
        if (i != minIndex){
            int buf = array[i];
            array[i] = array[minIndex];
            array[minIndex] = buf;
            exchangeCount++;
        }
    }    
    
    return exchangeCount;
}