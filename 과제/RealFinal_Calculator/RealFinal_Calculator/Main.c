#include <stdio.h>
#include <stdlib.h>
#include "ExpTree.h"

int main(void)
{
	char exp[100] = "(2^2+3^2*2)+(8/2%2)";
	char result[100];
	InfixToPostfix(exp, result);

	printf("%s\n", result);
	Tree* eTree = MakeExpTree(result);

	printf("연산의 결과: %d \n", Eval(eTree));
	return 0;
}