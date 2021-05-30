#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct _node {
	element data;
	struct _node *left, *right;
}Node;

Node* initNode(char item) {
	Node* n = (Node*)malloc(sizeof(Node));
	n->data = item;
	n->left = n->right = NULL;
	return n;
}	// 노드 생성

Node* searchTree(Node* n, char item) {
	if (n != NULL) {
		if (n->data == item) {
			return n;
		}
		else{
			Node* temp = searchTree(n->left, item);
			if (temp != NULL)
				return temp;
			else
				return searchTree(n->right, item);
		}
	}
	return NULL;
}	// 트리 전체 순회
void inputData(Node* n, char d1, char d2, char d3) {
	n->data = d1;

	if (d2 != '.')
		n->left = initNode(d2);

	if (d3 != '.')
		n->right = initNode(d3);
}
void preorder(Node* root) {
	//printf("pre");
	if (root != NULL) {
		printf("%c", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(Node* root) {
	//printf("in");
	if (root != NULL) {
		inorder(root->left);
		printf("%c", root->data);
		inorder(root->right);
	}
}

void postorder(Node* root) {
	//printf("post");
	if (root != NULL) {
		postorder(root->left);// 왼쪽서브트리 순회
		postorder(root->right);// 오른쪽서브트리순회
		printf("%c", root->data);  // 노드 방문
	}
}

int main(void) {
	int iter = 0;
	Node* root = initNode(NULL);
	Node* temp;
	scanf("%d", &iter);

	for (int i = 0; i < iter; i++) {
		char ch1,ch2,ch3 = 0;
		scanf("%c %c %c", &ch1, &ch2, &ch3);
		getchar();
		temp = searchTree(root, ch1);
		if (temp != NULL)
			inputData(temp, ch1, ch2, ch3);
		else
			inputData(root, ch1, ch2, ch3);
	}

	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
}