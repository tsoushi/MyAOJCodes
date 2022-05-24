#include <stdio.h>

int main(void) {
    int length;

    int max;
    int min;
    long sum;

    scanf("%d", &length);
    
    int buf;
    scanf("%d", &buf);
    max = buf;
    min = buf;
    sum = buf;

    for (int i = 1; i < length; i++){
        int buf;
        scanf("%d", &buf);
    
        if (buf > max) {
            max = buf;
        }
        if (buf < min) {
            min = buf;
        }
        sum += buf;
    }
    printf("%d %d %ld\n", min, max, sum);

}