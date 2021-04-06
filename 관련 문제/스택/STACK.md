### STACK

---

#### INDEX

* 10828



#### CONTENTS

* :bulb:10828

  > ​정수를 저장하는 스택을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.
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

