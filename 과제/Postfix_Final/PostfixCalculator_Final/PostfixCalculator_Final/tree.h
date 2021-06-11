#ifndef __TREE_H__
#define __TREE_H__

typedef struct Node {
	int c;
	struct Node* left, * right;
}Node;
#pragma once
typedef int Data;
typedef struct _tree {
	Data data;
	struct _tree* left, * right;
}Tree;

Tree* create(void);
Data getData(Tree*);
void setData(Tree*, Data);
Tree* getLeft(Tree*);
Tree* getRight(Tree*);
void MakeLeftTree(Tree*, Tree*);
void MakeRightTree(Tree*, Tree*);

#endif