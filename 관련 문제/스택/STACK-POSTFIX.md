### POSTFIX

---

#### OVERVIEW

- 중위표기식을 후위표기식으로 바꾸기 등과 같은 스택 응용 관련 개념과 문제풀이를 정리할 공간



#### INDEX

- 중위표기식과 후위 표기식
- 중위 표기식을 후위표기식으로 바꾸기
- 문제풀이



#### CONTENT

---

##### THEORY



**중위 표기식** : 연산자를 두 피연산자 사이에 표기하는 방법으로 가장 일반적으로 사용되는 표현방법, 이항 연산자 표현에 적합하며 산술연산, 논리 연산, 비교 연산에 주로 사용함

> *(A+B)* * *(C+D)*



**전위 표기식** : 연산자를 먼저 표시하고 연산에 필요한 피연산자를 나중에 표시하는 방법

> **(+(AB) - (CD))*



**후위 표기식** : 피연산자를 먼저 표시하고 연산자를 나중에 표시하는 방법

> *AB+CD-*\*



#### IDEA

* 문자열을 입력받아 앞에서부터 읽고 연산자는 스택에 넣은 후 뒤로 보낸다.
* 피연산자는 뒤로 보내지 않고 바로 출력한다.
* 괄호가 있다면 괄호도 연산자로 취급한다.
* 여는 괄호는 연산자 우선순위가 가장 낮다.
* 닫는 괄호를 만나게 된다면 스택에 들어있는 연산자를 '(' 연산자가 나올 때까지 POP 한다.



#### CODE

**전체 코드**

```C
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 6031)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element;
typedef struct {
	int size;
	element* data;
	int top;
}StackType;

void init(StackType* s) {
	s->size = 1;
	s->top = -1;
	s->data = (element*)malloc(sizeof(element) * s->size);
}

int is_full(StackType* s) {
	return (s->top == s->size - 1);
}

int is_empty(StackType* s) {
	return (s->top == -1);
}

void push(StackType* s, element* item) {
	if (is_full(s)) {
		s->size *= 2;
		s->data = (element*)realloc(s->data, sizeof(element) * s->size);
	}
	s->data[++(s->top)] = *item;
}

element pop(StackType* s) {
	if (s->top == -1) {
		return -1;
	}

	else{
		return s->data[(s->top)--];
	}
}

int priority(char* ch) {
	switch (*ch)
	{
	case '*':
	case '/':
		return 2;

	case '+':
	case '-':
		return 1;

	default:
		return -1;
	}
}

void calculate(StackType* s, char* infix) {	//infix : 입력값
	char *c;

	for (int i = 0; i < strlen(infix); i++) {
		switch (infix[i]) {
		case '+': case '-': case '*': case '/':

			while (!is_empty(&(*s)) && priority(&infix[i]) <= priority(&(s->data[s->top]))) {
				printf("%c", pop(&(*s)));
			}
			push(&(*s), &infix[i]);
			break;

		case '(':
			push(&(*s), &infix[i]);
			break;

		case ')':
			c = &(s->data[s->top]);
			while (*c != *"(") {
				printf("%c", pop(&(*s)));
				c = &(s->data[s->top]);
			}
			pop(&(*s));
			break;

		default:
			printf("%c", infix[i]);
			break;
		}
	}

	while (s->top != -1) {
		printf("%c", pop(&(*s)));
	}
}

int main(void) {
	StackType Stack;
	init(&Stack);
	char value[100] = { 0, };
	scanf("%s", value);
	int idx = 0;
	calculate(&Stack, value);
}
```



**구조체**

```c
typedef char element;
typedef struct {
	int size;
	element* data;
	int top;
}StackType;

```

- 구조체의 스택은 동적할당되어, 만약 스택이 가득차게 되면 이전의 size의 2배로 늘린다.



**함수**

```C
void init(StackType* s);
int is_full(StackType* s);
int is_empty(StackType* s);
void push (StackType* s, element* item);
element pop(StackType* s);
int priority(char* ch);
void calculate(StackType* s, char* infix);
```

- init : 구조체로 구현된 스택을 초기화한다.
- is_full : 스택이 할당된 메모리 크기만큼 가득 찼는가를 판별하는 함수
- is_empty : 스택이 비어있는지 확인하는 함수
- push : 스택에 값을 집어넣는 함수
- pop : 스택에 가장 마지막에 들어온 값을 반환함과 동시에 지우는 함수
- priority : 연산자 우선순위를 판별하여 크기로 리턴하는 함수
- calculate : idea의 내용을 기반으로 후위 표기식으로 변환하여 출력하는 함수.



**결과**

> (a/d\*e-b\*c)+f/g-(h-i)*j+k-l\*(m-n)+o\*p

![success!](https://github.com/Cycrypto/DataStructure/blob/master/IMG/boj_stack_success4.JPG)

