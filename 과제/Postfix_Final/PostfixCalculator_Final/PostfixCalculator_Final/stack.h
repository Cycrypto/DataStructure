#ifndef __STACK_H__
#define __STACK_H__

#define TRUE	1
#define FALSE	0

// typedef int Data;
typedef int Data;

typedef struct _node
{
	Data data;
	struct _node* next;
} StackNode;

typedef struct _listStack
{
	StackNode* head;
} ListStack;


typedef ListStack Stack;

void SInit(Stack* pstack);
int SIsEmpty(Stack* pstack);

void SPush(Stack* pstack, Data data);
Data SPop(Stack* pstack);
Data SPeek(Stack* pstack);

#endif