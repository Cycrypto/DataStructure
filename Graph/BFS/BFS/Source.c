#define _CRT_SECURE_NO_WARNINGS	
#include <stdio.h>	
#include <math.h>

int main(void) {
	float a = 0, b = 0, c = 0;
	
	printf("<<< �л� ����(-10.0 ~ + 10.0) �Է� : ");
	scanf("%f %f %f", &a, &b, &c);
	printf(">>> �л����� ����: \t %.1f %.1f %.1f\n", a, b, c);
	printf(">>> �ִ밪 : %.1f\n", a > b ? ((a > c) ? a : ((c > b) ? c : b)) : ((b > c) ? b : (c > a) ? c : a));
	printf(">>> �ּҰ� : %.1f\n", a < b ? ((a < c) ? a : ((c < b) ? c : b)) : ((b < c) ? b : (c < a) ? c : a));
	float avr = (a + b + c) / 3;
	printf("��հ� : %.3f\n", avr);
	printf("�л갪 : %.3f\n", (pow(a - avr, 2) + pow(b - avr, 2) + pow(c - avr, 2))/3);

}
