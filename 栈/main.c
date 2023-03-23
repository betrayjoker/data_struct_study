#include"main.h"

//stack(Last In First Out)LIFO (1/n+1)C2n n;
bool InitStack(SqStack *S) {
	(*S).top = -1;
}

bool Empty(SqStack S) {
	if (S.top == -1)
		return true;
	return false;
}

bool Push(SqStack* S, int x) {//1  2  4  
	if ((*S).top == MaxSize - 1)
		return false;
	//(*S).top++;
	(*S).data[++(*S).top] = x;
	return true;
}

bool Pop(SqStack* S, int* x) {
	if ((*S).top == -1)
		return false;
	*x = (*S).data[(*S).top--];
	return true;
}

bool GetTop(SqStack S, int* x) {
	if (S.top == -1)
		return -1;
	*x = S.data[S.top];
	return true;
}

int main() {
	SqStack S;
	int i=0;
	InitStack(&S);
	int InDate[] = { 1,2,3,4,5,6,7,8,9 };
	while (i != 9) {
		Push(&S, InDate[i++]);
	}
	if (i = Empty(S))
		printf("Îª¿Õ");
	else
		printf("²»Îª¿Õ");
	i = S.top;
	
	while (i != -1) {
		printf("%4d  ", S.data[i]);
		i--;
	}
	return 0;
}