#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"
#include "tree.h"

Stack* top;	//stack�� top ��� ������ ���� ������ ����
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

//char* concat(const char* s1, const char* s2) {
//	char* res = malloc(100);
//	strcpy(res, ' ');
//	strncat(res, s2, 1);
//	printf("A");
//	printf("%s\n", res);
//	return res;
//}

void append(char* dst, char c) {
	char* p = dst;
	while (*p != '\0') p++; // ���ڿ� �� Ž��
	*p = c;
	*(p + 1) = '\0';
}

char* infixToPostfix(const char* s) {
	char top;
	char result[1024] = "\0";

	int size = 0;
	int length = strlen(s);

	Stack* st;
	StackInit(&st);	// ���� ����
	for (int i = 0; i < length; i++) {
		//printf("%d \n", i);
		if (isOperator(s[i]) != 0) {	//�����ڶ��..
			//printf("a\n");
			while (!Stack_empty(&st) && (isOperator(s[i]) <= isOperator(peek(&st)))) {
				//printf("%c", StackPop(&st));
				append(result, StackPop(&st));
				size--;
			}
			StackPush(&st, s[i]);
			size++;
		}

		else if (s[i] == '(') {	//���� ��ȣ
			//printf("b\n");
			StackPush(&st, s[i]);
			size++;
		}

		else if (s[i] == ')') {	// �ݴ� ��ȣ
			//printf("c\n");
			top = StackPop(&st);
			size--;
			while (top != '(') {
				//append(result, StackPop(&st));
				//strcat(result, StackPop(&st));
				append(result, top);
				top = StackPop(&st);
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
		append(result, StackPop(&st));
		//printf("%c", StackPop(&st));
		size--;
	}
	return result;
}

void calcError(char* str) {
	fprintf(stderr, str);
	exit(1);
}

void ShowPostOrder(Node* tree) {
	if (tree != NULL) {
		ShowPostOrder(tree->left);
		ShowPostOrder(tree->right);
		printf("%c ", tree->c);
	}
}

Tree* evalExpression(char *s) {
	int opr1, opr2, value, i = 0;
	Stack* stack = NULL;
	StackInit(&stack);	//���� ����

	Tree* expTree = NULL;
	top = NULL;
	printf("%s\n", s);
	for (int i = 0; i < strlen(s); i++) {
		printf("%d ", i);
		expTree = create();	//Ʈ�� ��� ����
		if (isdigit(s[i])) {
			expTree->data = s[i];	//Ʈ����忡 �� ����
			printf("[digit]");
		}

		else {
			MakeRightTree(expTree, StackPop(&stack));
			MakeLeftTree(expTree, StackPop(&stack));
			expTree->data = s[i];
		}
		StackPush(&stack, expTree);
	}
	return StackPop(&stack);	//���ÿ� Ʈ���� �����.
}

