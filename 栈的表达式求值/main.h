#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef enum { false, true }bool;

//((15 / (7 - (1 + 1))) * 3 - (2 + (1 + 1))
// 两个栈 一个放结果 一个放过程，结果的栈存放的是数字和符号，过程中仅存放符号

typedef struct {
	char data;
	struct Sqstack* next;
}Sqstack,*SqSTACK;

bool InitStack(SqSTACK *S);

bool PutStack(SqSTACK* S, char x);

bool PopStack(SqSTACK* S, char* x);

bool Empty(SqSTACK S);

bool ToRPN(char *PN,SqSTACK* result);

int Len(char *PN);

char* GetElem();