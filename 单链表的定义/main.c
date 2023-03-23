#include"main.h"
#pragma warning(disable:4996)
//typedef enum { false, true }bool;


//typedef struct LNode {
//	int data;
//	struct LNode* next;
//}LNode, * LinkList;

bool InitList(LinkList* L) {
	*L = (LNode*)malloc(sizeof(LNode));
	if (*L == NULL)
		return false;
	(*L)->next = NULL;
	return true;
}

bool Empty(LinkList* L) {
	if ((*L)->next == NULL)
		return true;
	else
		return false;
}

bool PrintLink(LinkList* L) {
	LinkList h = (*L)->next;
	if (h->data == NULL) {
		printf("该单链表为空！\n");
		return false;
	}
	while (h != NULL) {
		printf("%d\n", h->data);
		h = h->next;
	}
	return true;
}

LNode* GetElem(LinkList L, int i) {
	if (i < 0)
		return NULL;
	if (i == 0)
		return L;
	LNode* p;
	p = L;
	int j = 1;//1 2 3 4 5
	while (p != NULL && j < i) {
		p = p->next;
		j++;
	}
	return p;
}

bool ListInsert(LinkList *L, int i, int e) {
	if (i < 1)
		return false;
	//int j = 0;//1 2 3 4 5
	//LNode* p;
	//p = *L;
	//while (p != NULL && j < i - 1) {
	//	p = p->next;
	//	j++;
	//}
	LNode* p = GetElem(*L,i-1);
	return InsertNextNode(p, e);
	/*if (p == NULL)
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;*/
}

bool InsertNextNode(LNode* p, int e) {
	if (p == NULL)
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)
		return false;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

bool InsertPriorNode(LNode* p, int e) {
	if (p == NULL)
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)
		return false;
	s->data = p->data;
	s->next = p->next;
	p->data = e;
	p->next = s;
	return true;
}

bool ListDelete(LinkList* L, int i,int *e) {
	if (i < 1)
		return false;
	LNode* p = *L;//1 2 3 4 5
	int j = 0;
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	//LNode* p = GetElem(L, i - 1);
	if (p == NULL)
		return false;
	if (p->next == NULL)
		return false;
	LNode* q = p->next;
	e = q->data;
	p->next = q->next;
	free(q);
	//p->next = (p->next)->next;
	return true;
	
}

bool DeleteNode(LNode* p) {
	if (p == NULL)
		return false;
	LNode* q = p->next;//1 2 3 4(q) 5
	p->data = q->data;
	p->next = q->next;
	free(q);
	return true;
}

LNode* LocateElem(LinkList L, int e) {
	LNode* p = L->next;
	while (p != NULL && p->data != e) {
		p = p->next;
	}
	return p;
}

int length(LinkList L) {
	LNode* p = L->next;
	int len = 0;
	while (p != NULL) {
		p = p->next;
		len++;
	}
	return len;
}

bool List_TailInsert(LinkList* L) {
	*L = (LinkList)malloc(sizeof(LNode));
	if (*L == NULL) {
		free(*L);
		return false;
	}
	LinkList node = NULL;
	LinkList end = NULL;
	(*L)->next = NULL;
	end = *L;
	int count = 0;
	
	/*for (int i = 0; i < count; i++) {
		node = (LNode*)malloc(sizeof(LNode));
		node->data = i + 1;
		end->next `= node;
		end = node;
	}*/
	scanf("%d", &count);
	while (count != 9999) {
		node = (LNode*)malloc(sizeof(LNode));
		if (node == NULL)
			return false;
		node->data = count;
		end->next = node;
		end = node;
		scanf("%d", &count);
	}
	end->next = NULL;
	return true;
}

bool List_HeadInsert(LinkList* L) {
	*L = (LinkList)malloc(sizeof(LNode));
	if (L == NULL) {
		free(*L);
		return false;
	}
	LNode* head = NULL;
	LNode* node = NULL;// 0 1 2 3 4
	(*L)->next = NULL;
	head = *L;         //  5
	int x = 0;
	scanf("%d", &x);
	while (x != 9999) {
		node = (LNode*)malloc(sizeof(LNode));
		if (node == NULL) {
			free(*L);
			return false;
		}
		node->data = x;
		node->next = head->next;
		head->next = node;
		scanf("%d", &x);
	}
	return true;
}

bool NoNode_HeadInsert(LinkList* L) {
	*L = (LinkList)malloc(sizeof(LNode));
	if (*L == NULL) {
		free(*L);
		return false;
	}
	(*L)->next = NULL;
	LNode* node = NULL;
	int x;
	scanf("%d", &x);
	while (x != 9999) {
		LNode* node = (LNode*)malloc(sizeof(LNode));//0 1 2 3 4
		if (node == NULL) {// 2 1
			free(node);
			return false;
		}
		node->data = x;
		node->next = NULL;
		if ((*L) == NULL) {
			*L = node;
		}
		else {
			node->next = *L;
			*L = node;
		}
		scanf("%d", &x);
	}
	return true;
}
bool NoNode_TailInsert(LinkList* L) {
	*L = (LinkList)malloc(sizeof(LNode));
	if (*L == NULL) {
		free(*L);
		return false;
	}
	(*L)->next = NULL;
	LNode* end = NULL;
	LNode* node = NULL;
	end = *L;
	int x;
	scanf("%d", &x);
	while (x != 9999) {
		node = (LNode*)malloc(sizeof(LNode));
		if (node == NULL) {
			free(node);
			return false;
		}
		node->data = x;
		node->next = NULL;//1 2
		if (*L == NULL) {
			*L = node;
			end = *L;
		}
		else {
			end->next = node;
			end = node;
		}
		scanf("%d", &x);
	}
	return true;

}



int main() {
	LinkList L;
	/*L = (LinkList)malloc(sizeof(LNode));
	if (L == NULL) {
		free(L);
		return 0;
	}*/
	List_HeadInsert(&L);
	PrintLink(&L);
	//L = List_HeadInsert(L);
	//InitList(&L);  
	//if (Empty(&L))
	//	printf("该单链表为空!\n");
	//else
	//	printf("该单链表中有脏数据！\n");
	////ListInsert(&L, 1, 2);
	//printf("%d\n", length(L));
	
	
	//LNode* p = GetElem(L, 1);
	//printf("\n%d", p->data);
	//system("pause");
	return 0;
}