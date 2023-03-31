#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 255
typedef enum { false, true }bool;

typedef struct {
	char data[MAXSIZE];
	int lenth;
}SString;

bool SubString(SString* sub, SString S, int pos, int lenth);

int StrCompare(SString S, SString T);

int Index(SString S, SString T);

int Index_KMP(SString S, SString T, int next[]);
