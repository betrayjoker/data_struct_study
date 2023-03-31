#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAXLEN 255

typedef enum { false, true }bool;

typedef struct {
	char ch[MAXLEN];
	int length;
}HString;

bool InitString(HString* H);

bool SubString(HString* Sub, HString H, int pos, int len);

int StrCompare(HString S, HString T);

int Index(HString S, HString T);
