#include<stdio.h>
#include<stdlib.h>
typedef enum { false,true }bool;
typedef struct {
	int value;
}ElemType;

typedef struct {
	ElemType data;
	struct BiTNode* rchild, * lchild;
	//struct BiTNode* parent;
}BiTNode,*BiTree;

bool PreOrder(BiTree T);

bool visit(BiTree T);

int treeDepth(BiTree T);

