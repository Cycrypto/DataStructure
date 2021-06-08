#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
Tree* create(void) {
	Tree* t = (Tree*)malloc(sizeof(Tree));
	t->left = NULL;
	t->right = NULL;
}

Data getData(Tree* t) {
	return t->data;
}

void setData(Tree* t, Data d) {
	t->data = d;
}

Tree* getLeft(Tree* t) {
	return t->left;
}

Tree* getRight(Tree* t) {
	return t->right;
}

void MakeLeftTree(Tree* main, Tree* sub) {
	if (main->left != NULL)
		free(main->left);
	main->left = sub;
}
void MakeRightTree(Tree* main, Tree* sub) {
	if (main->right != NULL)
		free(main->right);
	main->right = sub;
}
