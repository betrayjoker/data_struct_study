#include<stdio.h>
#include<stdlib.h>
typedef enum{false,true}bool;

typedef struct {
	int data;
	struct LinkNode* next;
}LinkNode;

typedef struct {
	LinkNode* front, * rear;
}LinkQueue;

bool InitQueue(LinkQueue* Q);

bool Empty(LinkQueue Q);

bool EnQueue(LinkQueue* Q, int x);

bool DeQueue(LinkQueue* Q, int* x);

