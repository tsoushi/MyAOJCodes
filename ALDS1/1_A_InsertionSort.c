#include <stdio.h>

void insertionSort(int*, int);
void printArray(int*, int);

int main(void){
    int length;
    int array[100];

    scanf("%d", &length);
    
    for (int i = 0; i < length; i++){
        scanf("%d", &array[i]);
    }
    
    insertionSort(array, length);
    printArray(array, length);
}

void insertionSort(int *array, int length){
    for (int i = 1; i < length; i++){
        int buf = array[i];
        int j = i - 1;

        printArray(array, length);
        
        while (j >= 0 && array[j] > buf){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = buf;
    }
}

void printArray(int *array, int length){
    for (int i = 0; i < length; i++){
        printf("%d", array[i]);
        if (i != length-1){
            printf(" ");
        } else {
            printf("\n");
        }
    }
}
