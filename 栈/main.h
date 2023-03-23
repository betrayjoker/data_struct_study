#include<stdio.h>
#include<stdlib.h>
#define MaxSize 10
typedef enum{false,true}bool;

typedef struct {
	int data[MaxSize];
	int top;
}SqStack;

bool Empty(SqStack S);

bool InitStack(SqStack S);

bool Push(SqStack* S, int x);

bool Pop(SqStack* S, int* x);

bool GetTop(SqStack S, int* x);