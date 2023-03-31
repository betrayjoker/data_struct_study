#include<stdio.h>
#include<stdlib.h>
typedef enum { false, true }bool;
typedef struct {
	int value;
	bool isEmpty;
}TreeNode;

bool InitTree(TreeNode* t);
