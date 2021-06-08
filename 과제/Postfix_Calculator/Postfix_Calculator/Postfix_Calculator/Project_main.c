#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Calculator.h"
#include "tree.h"

int main(void) {
	//const char exp[] = "12+3/4*";
	const char exp[] = "(1+2)/3*4";
	char *result = infixToPostfix(&exp);
	//printf("%s\n", result);
	Node* tree = evalExpression(result);
	//Node* tree = evalExpression(exp);

	ShowPostOrder(tree);
}