#pragma once
#include "tree.h"
int isOperator(char c);
int evalExpression(char* s);
void ShowPostOrder (Node* tree);
char* infixToPostfix(const char* s);
char* concat(const char* s1, const char* s2);
void append(char* dst, char c);