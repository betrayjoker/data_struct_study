#include "main.h"

bool InitDLinkList(DLinkList* L) {
	*L = (DLinkList)malloc(sizeof(DNode));
	if (*L == NULL) {
		free(*L);
		return false;
	}//
	(*L)->prior = NULL;
	(*L)->next = NULL;
	return true;
}

bool Empty(DLinkList* L) {
	if ((*L)->next == NULL)
		return true;
	else
		return false;

}

//void InserList(DLinkList  L, int i, int e) {
//	DLinkList s, p;
//	p = L;
//	int count = 0;
//	s = (DNode*)malloc(sizeof(DNode));
//	s->data = e;
//	while (count < i - 1 && p != NULL) {
//		p = p->next;
//		count++;
//
//	}
//	s->next = p->next;
//	if (p->next != NULL)
//		p->next->prior = s;
//	p->next = s;
//	s->prior = p;
//	printf("²åÈë³É¹¦\n");
//}

bool DeleteDNode(DNode* p) {
	if (p == NULL)//p e q 
		return false;
	DNode* q = p->next;
	if (q == NULL)
		return false;
	p->next = q->next;
	if (q->next != NULL)
		q->next->prior = p;
	free(q);
	return true;
}

int main() {
	DLinkList L;
	InitDLinkList(&L);

	return 0;
}