#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef enum{false,true}bool;

typedef struct {
	char ch[4];
	struct StringNode* next;
}StringNode,*String;

bool SubString(String* sub, String S, int pos, int len);
