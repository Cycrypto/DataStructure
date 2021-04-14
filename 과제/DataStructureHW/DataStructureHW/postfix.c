#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;		// ���� ����(element)�� �ڷ����� int�� ���� 

typedef struct  stackNode {	// ������ ��带 ����ü�� ����
	element data;
	struct stackNode* link;
} stackNode;

stackNode* top;				// ������ top ��带 �����ϱ� ���� ������ top ����

// ������ ���� �������� Ȯ���ϴ� ����
int isEmpty() {
	if (top == NULL) return 1;
	else return 0;
}

// ������ top�� ���Ҹ� �����ϴ� ����
void push(element item) {
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));
	temp->data = item;
	temp->link = top;		// ���� ��带 top�� ���� ����
	top = temp;				// top ��ġ�� ���� ���� �̵�
}

// ������ top���� ���Ҹ� �����ϴ� ����
element pop() {
	element item;
	stackNode* temp = top;

	if (top == NULL) {		// ������ ���� ����Ʈ�� ���
		printf("\n\n Stack is empty !\n");
		return 0;
	}

	else {					// ������ ���� ����Ʈ�� �ƴ� ���
		item = temp->data;
		top = temp->link;	// top ��ġ�� ���� ��� �Ʒ��� �̵�
		free(temp);			// ������ ����� �޸� ��ȯ
		return item;		// ������ ���� ��ȯ
	}
}

// ���� ǥ��� ������ ����ϴ� ����
element evalPostfix(char* exp) {
	int opr1, opr2, value, i = 0;
	// char�� ������ �Ű������� ���� ���� exp�� ���̸� ����Ͽ� length ������ ����
	int length = strlen(exp);
	char symbol;
	top = NULL;
	for (int i = 0; i < length; i++) {
		switch (exp[i]) {
		case '+':
			opr2 = pop();	opr1 = pop();
			push(opr1 + opr2);	break;

		case '-':
			opr2 = pop();	opr1 = pop();
			push(opr1 - opr2);	break;

		case'*':
			opr2 = pop();	opr1 = pop();
			push(opr1 * opr2);	break;

		case'/':
			opr2 = pop();	opr1 = pop();
			push(opr1 / opr2);	break;
		
		default:
			value = exp[i] - '0';
			push(value);
			break;
		}
	}
	return pop();
}
// ���� exp�� ���� ó���� ��ģ �� ���ÿ� ���� �ִ� ������� pop�Ͽ� ��ȯ

void main(void) {
	int result;
	char* express = "35*62/-";
	printf("���� ǥ��� : %s\n", express);

	result = evalPostfix(express);
	printf("\n\n���� ��� => %d", result);

	getchar();
}