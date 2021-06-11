#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

Tree* MakeTree(void){
	Tree* nd = (Tree*)malloc(sizeof(Tree));

	nd->left = NULL;
	nd->right = NULL;
	return nd;
}

int GetData(Tree* t){
	return t->data;
}

void SetData(Tree* t, int data){
	t->data = data;
}

Tree* GetLeft(Tree* t){
	return t->left;
}

Tree* GetRight(Tree* t){
	return t->right;
}

void MakeLeft(Tree* main, Tree* sub){
	if (main->left != NULL)
		free(main->left);

	main->left = sub;
}

void MakeRight(Tree* main, Tree* sub){
	if (main->right != NULL)
		free(main->right);

	main->right = sub;
}