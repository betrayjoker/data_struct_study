#include<stdio.h>
#include<stdlib.h>

typedef enum{false,true}bool;

typedef struct {
	char data;
	struct Sqstack* next;
}Sqstack,*SqSTACK;

bool bracketcheck(char str[], int length);

bool InitStack(SqSTACK* S);

bool PutStack(SqSTACK* S, char x);

bool PopStack(SqSTACK* S, char* x);

bool Empty(SqSTACK S);