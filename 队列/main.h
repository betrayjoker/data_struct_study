#include<stdio.h>
#include<stdlib.h>
#define MaxSize 10
typedef enum{false,true}bool;

typedef struct {
	int data[MaxSize];
	int front, rear;
}SqQueue;
bool InitQueue(SqQueue* Q);
bool Empty(SqQueue Q);
bool DestroyQueue(SqQueue* Q);
bool EnQueue(SqQueue* Q,int x);
bool DeQueue(SqQueue* Q,int *x);
bool GetHead(SqQueue Q,int *x);
bool Full(SqQueue Q);

