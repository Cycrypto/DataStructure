#ifndef __EXP_TREE__
#define __EXP_TREE__

#include "Tree.h"

Tree* MakeExpTree(char exp[]);
int Eval(Tree* bt);
void InfixToPostfix(char infix_exp[], char postfix_exp[]);
#endif