#include <stdio.h>

int GCD(int, int);

int main(void){
    int x, y;
    scanf("%d%d", &x, &y);
    if (x < y){
        int buf = y;
        y = x;
        x = buf;
    }
    
    printf("%d\n", GCD(x, y));
}

int GCD(int x, int y){
    if (y == 0){
        return x;
    }
    return GCD(y, x % y);
}