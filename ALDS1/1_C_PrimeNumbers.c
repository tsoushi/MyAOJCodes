#include <stdio.h>
#include <math.h>

int isPrime(int);

int main(void){
	int length;
	int primeCount = 0;
	int num;

	scanf("%d", &length);
	for (int i = 0; i < length; i++){
	    scanf("%d", &num);
	    if (isPrime(num)==1){
	        primeCount++;
	    }
	}
	printf("%d\n", primeCount);
}

int isPrime(int n){
	if (n <= 1 || (n != 2 && n % 2 == 0)){
		return 0;
	} else {
		for (int i = 2; i <= sqrt(n) ; i++){
			if (n % i == 0){
				return 0;
			}
		}
	}
	return 1;
}
