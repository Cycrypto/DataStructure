#define _CRT_SECURE_NO_WARNINGS	
#include <stdio.h>	
#include <math.h>

int main(void) {
	float a = 0, b = 0, c = 0;
	
	printf("<<< 학생 점수(-10.0 ~ + 10.0) 입력 : ");
	scanf("%f %f %f", &a, &b, &c);
	printf(">>> 학생들의 점수: \t %.1f %.1f %.1f\n", a, b, c);
	printf(">>> 최대값 : %.1f\n", a > b ? ((a > c) ? a : ((c > b) ? c : b)) : ((b > c) ? b : (c > a) ? c : a));
	printf(">>> 최소값 : %.1f\n", a < b ? ((a < c) ? a : ((c < b) ? c : b)) : ((b < c) ? b : (c < a) ? c : a));
	float avr = (a + b + c) / 3;
	printf("평균값 : %.3f\n", avr);
	printf("분산값 : %.3f\n", (pow(a - avr, 2) + pow(b - avr, 2) + pow(c - avr, 2))/3);

}
