#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100

typedef enum{false,true}bool;

typedef struct {
	char value;
}ElemType;//���洢�����ݽṹ��ʼ��

typedef struct {
	ElemType data;
	struct TreeNode* lchild, * rchild;
	//TreeNode* parent;
	int ltag,rtag;
}TreeNode, * Tree;//���Ľṹ���ʼ��

typedef struct {
	TreeNode* temp;
	struct que* next;
}que;

typedef struct {
	que* front, * rear;
}LinkQueue;

bool InitTree(Tree* T);//��ʼ������ṹ��

bool PreOrder(Tree T);//�������

bool visit(Tree* T);//���ʴ˽��

//bool PopTree(Tree* T);

bool LevelOrder(Tree T);

bool CreateInThread(Tree* T);

bool InThread(Tree* T);
