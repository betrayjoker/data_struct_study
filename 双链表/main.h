#include <stdio.h>

typedef enum{false,true}bool;

typedef struct {
	int data;
	struct DNode* next;
	struct DNode* prior;
}DNode,*DLinkList;

bool InitDLinkList(DLinkList* L);

bool Empty(DLinkList* L);

bool InsertNextDNode(DNode* p, DNode* s);

bool DeleteDNode(DNode* p);

void InserList(DLinkList  L, int i, int e);
