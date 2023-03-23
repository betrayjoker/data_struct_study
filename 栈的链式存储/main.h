#include<stdio.h>
#include<stdlib.h>

typedef enum{false,true}bool;

typedef struct {
	int data;
	struct Linknode* next;
}Linknode, * Listack;

bool InitListnode(Listack* S);
bool PushList(Listack* S, int x);
int Length(Listack S);
bool Empty(Listack S);
bool GetTopList(Listack S);
bool PutList(Listack* S);
bool ToEmpty(Listack* S);
