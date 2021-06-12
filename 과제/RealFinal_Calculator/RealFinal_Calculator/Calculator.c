#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "Stack.h"
#include "Tree.h"

#define SIZE 100
char stack[SIZE];
int top = -1;

void push(char item){
	if (top >= SIZE - 1){
		printf("\nOVERFLOW");
	}
	else{
		top = top + 1;
		stack[top] = item;
	}
}

char pop(){
	char item;

	if (top < 0){
		printf("UNDERFLOW");
		getchar();
		exit(1);
	}
	else{
		item = stack[top];
		top = top - 1;
		return(item);
	}
}

int is_operator(char symbol)
{
	if (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '%' || symbol == '+' || symbol == '-'){
		return 1;
	}
	else{
		return 0;
	}
}

int precedence(char symbol)
{
	if (symbol == '^'){
		return 3;
	}
	else if (symbol == '*' || symbol == '/' || symbol == '%'){
		return 2;
	}
	else if (symbol == '+' || symbol == '-'){
		return 1;
	}
	else{
		return 0;
	}
}
void InfixToPostfix(char infix_exp[], char postfix_exp[]){
	int i, j;
	char item;
	char x;

	push('(');                  
	strcat(infix_exp, ")");

	i = 0;
	j = 0;
	item = infix_exp[i];

	while (item != '\0'){
		if (item == '('){
			push(item);
		}
		else if (isdigit(item) || isalpha(item)){
			postfix_exp[j] = item;
			j++;
		}
		else if (is_operator(item) == 1){
			x = pop();
			while (is_operator(x) == 1 && precedence(x) >= precedence(item)){
				postfix_exp[j] = x;
				j++;
				x = pop();
			}
			push(x);

			push(item);
		}
		else if (item == ')'){
			x = pop();
			while (x != '('){
				postfix_exp[j] = x;
				j++;
				x = pop();
			}
		}
		else{
			printf("\nInvalid infix Expression.\n");
			getchar();
			exit(1);
		}
		i++;


		item = infix_exp[i];
	}

	if (top > 0){
		printf("\nInvalid infix Expression.\n");
		getchar();
		exit(1);
	}

	if (top > 0){
		printf("\nInvalid infix Expression.\n");
		getchar();
		exit(1);
	}

	postfix_exp[j] = '\0';
}
Tree* MakeExpTree(char exp[]){
	Stack stack;
	Tree* pnode;

	int expLen = strlen(exp);
	int i;

	StackInit(&stack);

	for (i = 0; i < expLen; i++){
		pnode = MakeTree();

		if (isdigit(exp[i])){
			SetData(pnode, exp[i] - '0');
		}

		else{
			MakeRight(pnode, SPop(&stack));
			MakeLeft(pnode, SPop(&stack));
			SetData(pnode, exp[i]);
		}

		SPush(&stack, pnode);
	}

	return SPop(&stack);
}

int Eval(Tree* bt){
	int op1, op2;

	if (GetLeft(bt) == NULL && GetRight(bt) == NULL)
		return GetData(bt);

	op1 = Eval(GetLeft(bt));
	op2 = Eval(GetRight(bt));

	switch (GetData(bt)){
	case '+':
		return op1 + op2;

	case '-':
		return op1 - op2;

	case '*':
		return op1 * op2;

	case '/':
		return op1 / op2;

	case '^':
		return (int)pow(op1,op2);

	case '%':
		return op1 % op2;
	}
	return 0;
}

void ShowNodeData(int data){
	if (0 <= data && data <= 9)
		printf("%d ", data);
	else
		printf("%c ", data);
}
