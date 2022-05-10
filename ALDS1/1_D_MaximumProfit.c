#include <stdio.h>
#include <limits.h>

int max(int, int);
int min(int, int);

int main(void){
    int length;
    int maxDiff = INT_MIN;
    int minInt;
    int buf;

    scanf("%d%d", &length, &buf);
    minInt = buf;
    for (int i = 0; i < length-1; i++){
        scanf("%d", &buf);
        maxDiff = max(maxDiff, buf - minInt);
        minInt = min(minInt, buf);
    }
    printf("%d\n", maxDiff);
}

int max(int a, int b){
    if (a > b){
        return a;
    } else {
        return b;
    }
}

int min(int a, int b){
    if (a < b){
        return a;
    } else {
        return b;
    }
}