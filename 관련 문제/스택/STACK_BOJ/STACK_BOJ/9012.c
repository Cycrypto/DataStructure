#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char celement;

typedef struct {
	celement* data;
	int top;
	int size;
}StackType;

void init_stack(StackType* s) {
	s->top = -1;
	s->size = 1;
	s->data = (celement*)malloc(100);
}

void push(StackType* s, celement* item) {
	s->data[++(s->top)] = *item;	//마지막에 요소 추가
}

celement pop(StackType* s) {
	return (s->data[(s->top)--]);
}

int check(StackType* s, char* ch) {
	for (int i = 0; i < strlen(ch); i++) {
		switch (ch[i]) {
			case '(':
				push(s, &ch[i]);
				break;

			case ')':
				if (s->top != -1) {
					pop(s);
				}

				else
					return 0;
				break;
		}
	}
	return (s->top == -1)? 1 : 0;
}
int main(void) {
	StackType Stack;
	char ch[50] = { 0, };
	int input = 0;
	int result = 0;

	scanf("%d", &input);

	for (int j = 0; j < input; j++) {
		init_stack(&Stack);
		scanf("%s", ch);

		result = check(&Stack, ch);
		if (result)
			printf("YES\n");
		else
			printf("NO\n");
	}

}