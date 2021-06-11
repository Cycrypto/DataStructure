#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "tree.h"
#include "stack.h"

void append(char* dst, char c) {
	char* p = dst;
	while (*p != '\0') p++; // 문자열 끝 탐색
	*p = c;
	*(p + 1) = '\0';
}
int isOperator(char c) {
	if (c == '+' || c == '-') {
		return 1;
	}

	else if (c == '*' || c == '/' || c == '%') {
		return 3;
	}

	else if (c == '^') {
		return 5;
	}

	else {
		return 0;
	}

}
char* infixToPostfix(const char* s) {
	char top;
	char result[1024] = "\0";

	int size = 0;
	int length = strlen(s);

	Stack* st;
	SInit(&st);	// 스택 생성
	for (int i = 0; i < length; i++) {
		//printf("%d \n", i);
		if (isOperator(s[i]) != 0) {	//연산자라면..
			//printf("a\n");
			while (!SIsEmpty(&st) && (isOperator(s[i]) <= isOperator(SPeek(&st)))) {
				//printf("%c", StackPop(&st));
				append(result, SPop(&st));
				size--;
			}
			SPush(&st, s[i]);
			size++;
		}

		else if (s[i] == '(') {	//여는 괄호
			//printf("b\n");
			SPush(&st, s[i]);
			size++;
		}

		else if (s[i] == ')') {	// 닫는 괄호
			//printf("c\n");
			top = SPop(&st);
			size--;
			while (top != '(') {
				//append(result, StackPop(&st));
				//strcat(result, StackPop(&st));
				append(result, top);
				top = SPop(&st);
				size--;
			}
		}

		else {
			//printf("final\n");
			append(result, s[i]);
			//strcat(result, s[i]);
			//printf("%c",s[i]);
		}
	}

	while (size > 0) {
		append(result, SPop(&st));
		//printf("%c", StackPop(&st));
		size--;
	}
	return result;
}

Node* MakeExpTree(char *exp)
{
	printf("pointer-func : %p\n", &exp);
	Stack stack;
	Tree* pnode;

	int expLen = strlen(exp);
	int i;

	SInit(&stack);
	printf("%s\n", exp);
	//printf("[digit]%d\n", isdigit("t"));

	for (i = 0; i < expLen; i++)
	{
		pnode = create();
		
		if (isdigit(exp[i]))		// 피연산자라면...
		{
			printf("Y1\n");
			setData(pnode, exp[i] - '0');
			printf("Y2\n");
		}

		else					// 연산자라면...
		{
			printf("N1\n");
			MakeRightTree(pnode, SPop(&stack));
			printf("N2\n");
			MakeLeftTree(pnode, SPop(&stack));
			setData(pnode, exp[i]);
		}

		SPush(&stack, pnode);
	}

	return SPop(&stack);
}

int EvaluateExpTree(Node* bt)
{
	int op1, op2;

	if (getLeft(bt) == NULL && getRight(bt) == NULL)
		return getData(bt);

	op1 = EvaluateExpTree(getLeft(bt));
	op2 = EvaluateExpTree(getRight(bt));

	switch (getData(bt))
	{
	case '+':
		return op1 + op2;

	case '-':
		return op1 - op2;

	case '*':
		return op1 * op2;

	case '/':
		return op1 / op2;
	}

	return 0;
}

int main(void) {
	char exp[] = "(1+2)/(3+4)";
	printf("[pointer-main] %p\n", &exp);
	char* result = NULL;
	result = infixToPostfix(exp);
	Tree* t = MakeExpTree(result);	//얘가 문제임
	EvaluateExpTree(t);

}