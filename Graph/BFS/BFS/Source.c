#define _CRT_SECURE_NO_WARNINGS	//scanf	-> ����� �Է� �޴� ģ��
#include <stdio.h>	// printf , scanf + etc...


int main(void) {
	int input = 0;	//�޸𸮿� 4byte ����
	printf("%d\n", input);
	scanf("%d", &input);
	printf("%d", input);
}
