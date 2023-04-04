#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100

typedef enum{false,true}bool;

typedef struct {
	char value;
}ElemType;//树存储的数据结构初始化

typedef struct {
	ElemType data;
	struct TreeNode* lchild, * rchild;
	//TreeNode* parent;
	int ltag,rtag;
}TreeNode, * Tree;//树的结构体初始化

typedef struct {
	TreeNode* temp;
	struct que* next;
}que;

typedef struct {
	que* front, * rear;
}LinkQueue;

bool InitTree(Tree* T);//初始化链表结构树

bool PreOrder(Tree T);//先序遍历

bool visit(Tree* T);//访问此结点

//bool PopTree(Tree* T);

bool LevelOrder(Tree T);

bool CreateInThread(Tree* T);

bool InThread(Tree* T);
