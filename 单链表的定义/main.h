#include<stdio.h>
#include <stdlib.h>

typedef enum { false, true }bool;

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;

bool InitList(LinkList* L);

bool Empty(LinkList* L);

bool PrintLink(LinkList* L);

LNode* GetElem(LinkList L, int i);
	

bool ListInsert(LinkList* L, int i, int e);

bool InsertNextNode(LNode* p, int e);

bool InsertPriorNode(LNode* p, int e);
	

bool ListDelete(LinkList* L, int i, int* e);

bool DeleteNode(LNode* p);

LNode* LocateElem(LinkList L, int e);

int length(LinkList L);

bool List_TailInsert(LinkList* L);

bool List_HeadInsert(LinkList* L);

bool NoNode_HeadInsert(LinkList* L);

bool NoNode_TailInsert(LinkList* L);

