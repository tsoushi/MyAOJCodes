#include <stdio.h>

void insertionSort(int*, int);
void printArray(int*, int);

int main(void){
    int length;
    scanf("%d", &length);
    
    int array[100];
    for (int i = 0; i < length; i++){
        scanf("%d", &array[i]);
    }
    
    insertionSort(array, length);
    printArray(array, length);
}

void insertionSort(int *array, int length){
    for (int i = 1; i < length; i++){
        printArray(array, length);
        
        int buf = array[i];
        int ii = i - 1;
        
        while (ii >= 0 && array[ii] > buf){
            array[ii+1] = array[ii];
            ii--;
        }
        array[ii+1] = buf;
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