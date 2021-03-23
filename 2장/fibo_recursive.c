#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fib(int n){
	if (n == 0) return 0;
	if (n == 1) return 1;
	return (fib(n-1) + fib(n-2));
}

int main (void){
	int i = 10;
	int result = 0;
	clock_t start, stop;
	
	double duration;
	start = clock();
	result = fib(i);
	stop = clock();
	
	duration = (double)(stop - start) / CLOCKS_PER_SEC;
	printf("수행시간은 %f 초 입니다.\n", duration);
	printf("result = %d\n",result);
}
