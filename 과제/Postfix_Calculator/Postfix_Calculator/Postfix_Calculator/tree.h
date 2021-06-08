#pragma once
typedef struct Node {
	char c;
	struct Node* left, *right;
}Node;
#pragma once
typedef int Data;
typedef struct _tree {
	Data data;
	struct _tree* left, *right;
}Tree;

Tree* create(void);
Data getData(Tree*);
void setData(Tree*, Data);
Tree* getLeft(Tree*);
Tree* getRight(Tree*);
void MakeLeftTree(Tree*, Tree*);
void MakeRightTree(Tree*, Tree*);