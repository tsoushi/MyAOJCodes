#include <stdio.h>

void call(int);

int main(void){
    int n;
    scanf("%d", &n);
    call(n);
}

void call(int n){
    for(int i = 1; i <= n; i++){
        int x = i;
        if ( x % 3 == 0 ){
            printf(" %d", i);
            continue;
        }
        while (x != 0){
            if ( x % 10 == 3 ){
                printf(" %d", i);
                continue;
            }
            x /= 10;
        }
    }
    printf("\n");
}