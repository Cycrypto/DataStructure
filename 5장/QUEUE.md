### 큐

---

#### 정의

- 먼저 들어온 데이터가 먼저 나가는 자료구조



#### 구조

- **FIFO 구조 (First - In - First - Out)** : 먼저 들어온 데이터가 먼저 나감

  ![](C:\Users\jh01l\Desktop\KPU\2학년\자료구조\5장\IMG\Queue.JPG)

  

#### 예제

- **큐 추상데이터타입(ADT)**

  > * **create**(max_size) ::= 최대 크기가 max_size인 공백큐를 생성한다.
  >
  > * **init(q)** ::= 큐를 초기화한다.
  >
  > * **is_full**(s) ::= if(size== max_size) return TRUE; 
  >
  >   else return FALSE;
  >
  > * **is_empty**(s) ::= if(size == 0) return TRUE;
  >   else return FALSE;
  >
  > * **enqueue**(q, e) ::= if(is_full(q)) return ERROR_QUEUEFULL;
  >   else q의 끝에 e를 추가한다.
  >
  > * **dequeue**(q) ::= if(is_empty(q)) return ERROR_QUEUEEMPTY;
  >   else q의 맨 앞에 있는 e를 제거하여 반환한다.
  >
  > * **peek**(q) ::= if(is_empty(q)) return ERROR_QUEUEEMPTY;
  >   else q의 맨 앞에 있는 e를 읽어서 반환한다.

  

#### 선형 큐 구현(스스로 해보기)

```c
#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 5
#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct {
	int rear;
	int front;
	element data[MAX_SIZE];
}Queue;

void init(Queue* q) {
	q->rear = -1;
	q->front = -1;
}

int is_full(Queue* q) {
	return (q->rear == MAX_SIZE - 1);
}

int is_empty(Queue* q) {
	return (q->rear == q->front);
}

void enqueue(Queue* q, element item) {
	if (is_full(q)) {
		fprintf(stderr, "OVERFLOW!\n");
		exit(-1);
	}
	else {
		return q->data[++(q->rear)] = item;
	}
}

element dequeue(Queue* q) {
	if (is_empty(q)) {
		fprintf(stderr, "UNDERFLOW\n");
		exit(-1);
	}
	else {
		return q->data[++(q->front)];
	}
}
element peek(Queue* q) {
	if (is_empty(q)) {
		fprintf(stderr, "UNDERFLOW\n");
		exit(-1);
	}
	else {
		return q->data[q->front + 1];
	}
}
void queue_print(Queue* q) {
	for (int i = 0; i < MAX_SIZE; i++) {
		if (i <= q->front || i > q->rear) {
			printf("  |");
		}
		else
			printf("%d | ", q->data[i]);
	}
	printf("\n\n");
}

int main(void) {
	int item = 0;
	Queue Q;
	init(&Q);

	enqueue(&Q, 10); queue_print(&Q);
	enqueue(&Q, 20); queue_print(&Q);
	enqueue(&Q, 30); queue_print(&Q);

	item = dequeue(&Q); queue_print(&Q);
	item = dequeue(&Q); queue_print(&Q);
	item = dequeue(&Q); queue_print(&Q);
}
```



#### 선형 큐 구현(예시)

```c
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct { 				// 큐 타입
	int  front;
	int rear;
	element  data[MAX_QUEUE_SIZE];
} QueueType;

// 오류 함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType *q)
{
	q->rear = -1;
	q->front = -1;
}
void queue_print(QueueType *q)
{
	for (int i = 0; i<MAX_QUEUE_SIZE; i++) {
		if (i <= q->front || i> q->rear)
			printf("   | ");
		else
			printf("%d | ", q->data[i]);
	}
	printf("\n");
}

int is_full(QueueType *q)
{
	if (q->rear == MAX_QUEUE_SIZE - 1)
		return 1;
	else
		return 0;
}

int is_empty(QueueType *q)
{
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}

void enqueue(QueueType *q, int item)
{
	if (is_full(q)) {
		error("큐가 포화상태입니다.");
		return;
	}
	q->data[++(q->rear)] = item;
}

int dequeue(QueueType *q)
{
	if (is_empty(q)) {
		error("큐가 공백상태입니다.");
		return -1;
	}
	int item = q->data[++(q->front)];
	return item;
}

int main(void)
{
	int item = 0;
	QueueType q;

	init_queue(&q);

	enqueue(&q, 10); queue_print(&q);
	enqueue(&q, 20); queue_print(&q);
	enqueue(&q, 30); queue_print(&q);

	item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q);
	return 0;
}
```



#### 원형 큐 구현(스스로 해보기)

```c
#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 5
#include <stdio.h>

typedef int element;
typedef struct Queue{
	int rear;
	int front;
	element data[MAX_SIZE];
}Queue;

void init(Queue* q) {
	int rear = -1;
	int front = -1;
}

int is_full(Queue* q) {
	return ((q->rear + 1) % MAX_SIZE) == q->front;
}

int is_empty(Queue* q) {
	return (q->rear == q->front);
}

void enqueue(Queue* q, element item) {
	if (is_full(q)) {
		fprintf(stderr, "Queue Is Full!");
		exit(-1);
	}
	q->rear = (q->rear + 1) % MAX_SIZE;
	q->data[q->rear] = item;
}

element dequeue(Queue* q) {
	if (is_empty(q)) {
		fprintf(stderr, "Queue Is Empty!");
		exit(-1);
	}
	return q->data[q->front = (q->front + 1) % MAX_SIZE];
}

element peek(Queue* q) {
	return q->rear;
}

void queue_print(Queue* q)
{
	for (int i = 0; i < MAX_SIZE; i++) {
		if (i <= q->front || i > q->rear)
			printf("   | ");
		else
			printf("%d | ", q->data[i]);
	}
	printf("\n");
}

int main(void) {
	Queue q;
	init(&q);
	int item = 0;

	enqueue(&q, 10); queue_print(&q);
	enqueue(&q, 20); queue_print(&q);
	enqueue(&q, 30); queue_print(&q);

	item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q);

}
```





#### 원형 큐 구현 (예시 코드)

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// ===== 원형큐 코드 시작 ======
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct { // 큐 타입
	element  data[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;

// 오류 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 공백 상태 검출 함수
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 원형큐 출력 함수
void queue_print(QueueType* q)
{
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

// 삽입 함수
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// 삭제 함수
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

// 삭제 함수
element peek(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}
// ===== 원형큐 코드 끝 ======

int main(void)
{
	QueueType queue;
	int element;

	init_queue(&queue);
	printf("--데이터 추가 단계--\n");
	while (!is_full(&queue))
	{
		printf("정수를 입력하시오: ");
		scanf("%d", &element);
		enqueue(&queue, element);
		queue_print(&queue);
	}
	printf("큐는 포화상태입니다.\n\n");

	printf("--데이터 삭제 단계--\n");
	while (!is_empty(&queue))
	{
		element = dequeue(&queue);
		printf("꺼내진 정수: %d \n", element);
		queue_print(&queue);
	}
	printf("큐는 공백상태입니다.\n");
	return 0;
}
```



#### 느낀점

스택 관련 코드를 많이 작성해보고, 큐를 구현하니 한층 더 쉬웠다. 

동작 방식은 이전 C언어 수업시간에 맛보기로 구현한 링크드 리스트와 동일하여, 바로 구현하기에 무리가 없었다.

다만 교수님 코드와 다른 부분은 error 처리 함수가 따로 있던점과, is_empty, is_full 함수의 리턴 방식이지만 전체적으로 동일하다.



원형 큐의 경우 나머지 연산으로 큐를 회전 시킨다는 개념이 어려웠는데 손으로 몇번 반복해보니 이해가 되었다.