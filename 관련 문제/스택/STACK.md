## STACK

---

4장 스택과 관련한 boj 문제풀이를 업로드 할 공간.

[소스코드 위치](https://github.com/Cycrypto/DataStructure/tree/master/%EA%B4%80%EB%A0%A8%20%EB%AC%B8%EC%A0%9C/%EC%8A%A4%ED%83%9D/STACK_BOJ/STACK_BOJ)

### INDEX

---

* [10828](#10828)
* [9012](#9012)



### CONTENTS

---

#### 10828

> 정수를 저장하는 스택을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.
>
> 명령은 총 다섯 가지이다.
>
> - push X: 정수 X를 스택에 넣는 연산이다.
> - pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
> - size: 스택에 들어있는 정수의 개수를 출력한다.
> - empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
> - top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.

> (INPUT)
> 첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다.

> (OUTPUT)
>
> 출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.



```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct {
	element* data;
	int size;
	int top;
}StackType;

void init_stack(StackType* s) {
	s->size = 1;	//스택의 메모리 사이즈 / 실제 들어있는 값과는 차이가 있음
	s->data = (element)malloc(s->size * sizeof(element));
	s->top = -1;
}

void stack_push(StackType* s, element item) {
	if (s->size - 1 == s->top) {
		s->size *= 2;
		s->data = (element)realloc(s->data, s->size * sizeof(element));
	}
	s->data[++(s->top)] = item;
}

element stack_pop(StackType* s) {
	if (stack_empty(s)) {
		return -1;
	}

	else {
		return s->data[(s->top)--];
	}
}

element stack_size(StackType* s) {
	return s->top + 1;
}

int stack_empty(StackType* s) {
	return (s->top == -1);
}

int stack_top(StackType* s) {
	if (stack_empty(s))
		return -1;
	else
		return (s->data[s->top]);
}

int main(void) {
	StackType STACK;
	init_stack(&STACK);
	
	int iter = 0;
	scanf("%d", &iter);
	for (int i = 0; i < iter; i++) {
		char* func = malloc(sizeof(char) * 10);
		int param = 0;
		scanf("%s", func);
		if (!strcmp(func, "push")) {
			scanf("%d", &param);
			stack_push(&STACK, param);
		}

		else if (!strcmp(func, "pop")) {
			printf("%d\n", stack_pop(&STACK));
		}

		else if (!strcmp(func, "size")) {
			printf("%d\n", stack_size(&STACK));
		}

		else if (!strcmp(func, "empty")) {
			printf("%d\n", stack_empty(&STACK));
		}

		else {
			printf("%d\n", stack_top(&STACK));
		}
	}
}
```

> :bulb: 가장 기본적인 스택 구현 문제, 문자열 처리에서 살짝 삐끗했지만 스택 자체 구현은 큰 문제 없었던 부분

![success!](https://github.com/Cycrypto/DataStructure/blob/master/IMG/boj_stack_success.JPG)





#### 9012

> 괄호 문자열(Parenthesis String, PS)은 두 개의 괄호 기호인 ‘(’ 와 ‘)’ 만으로 구성되어 있는 문자열이다. 그 중에서 괄호의 모양이 바르게 구성된 문자열을 올바른 괄호 문자열(Valid PS, VPS)이라고 부른다. 한 쌍의 괄호 기호로 된 “( )” 문자열은 기본 VPS 이라고 부른다. 만일 x 가 VPS 라면 이것을 하나의 괄호에 넣은 새로운 문자열 “(x)”도 VPS 가 된다. 그리고 두 VPS x 와 y를 접합(concatenation)시킨 새로운 문자열 xy도 VPS 가 된다. 예를 들어 “(())()”와 “((()))” 는 VPS 이지만 “(()(”, “(())()))” , 그리고 “(()” 는 모두 VPS 가 아닌 문자열이다. 
>
> 여러분은 입력으로 주어진 괄호 문자열이 VPS 인지 아닌지를 판단해서 그 결과를 YES 와 NO 로 나타내어야 한다. 



> (INPUT)
>
> 입력 데이터는 표준 입력을 사용한다. 입력은 T개의 테스트 데이터로 주어진다. 입력의 첫 번째 줄에는 입력 데이터의 수를 나타내는 정수 T가 주어진다. 각 테스트 데이터의 첫째 줄에는 괄호 문자열이 한 줄에 주어진다. 하나의 괄호 문자열의 길이는 2 이상 50 이하이다. 



> (OUTPUT)
>
> 출력은 표준 출력을 사용한다. 만일 입력 괄호 문자열이 올바른 괄호 문자열(VPS)이면 “YES”, 아니면 “NO”를 한 줄에 하나씩 차례대로 출력해야 한다. 



```c
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
```



> :bulb: 반례잡기 까다로웠던 문제, 몇번 실패 이후에 성공하였음
>
> :bulb: 원래 코드는 flag를 리턴받아서 -2인 경우 스택 언더플로우가 발생한 시점을 잡아내어 실패를 뽑아내는 거였으나, 반복문을 돌며 계속 초기화되어 원하는대로 동작하지 않았음.
>
> :bulb: 이후 Check라는 함수를 만들어 체크함.

![success!](https://github.com/Cycrypto/DataStructure/blob/master/IMG/boj_stack_success2.JPG)