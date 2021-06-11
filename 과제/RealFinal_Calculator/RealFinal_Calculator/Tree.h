#ifndef __TREE__
#define __TREE__


typedef struct _Tree{
	int data;
	struct _Tree* left;
	struct _Tree* right;
} Tree;

Tree* MakeTree(void);
int GetData(Tree*);
void SetData(Tree*, int);

Tree* GetLeft(Tree*);
Tree* GetRight(Tree*);

void MakeLeft(Tree*, Tree*);
void MakeRight(Tree*, Tree*);
#endif