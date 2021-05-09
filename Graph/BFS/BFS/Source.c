#define _CRT_SECURE_NO_WARNINGS	//scanf	-> 사용자 입력 받는 친구
#include <stdio.h>	// printf , scanf + etc...


int main(void) {
	int input = 0;	//메모리에 4byte 공간
	printf("%d\n", input);
	scanf("%d", &input);
	printf("%d", input);
}
