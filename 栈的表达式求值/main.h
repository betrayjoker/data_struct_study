#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef enum { false, true }bool;

//((15 / (7 - (1 + 1))) * 3 - (2 + (1 + 1))
// ����ջ һ���Ž�� һ���Ź��̣������ջ��ŵ������ֺͷ��ţ������н���ŷ���

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

bool bracketcheck(char *str, int length);

int IfOp(char x);

bool CompareOp(char a, char b);

bool OutputStack(SqSTACK S);

bool RoutPutStack(SqSTACK S);

int LengthStack(SqSTACK S);