#include<stdio.h>

#define MaxSize 10
typedef struct {
	int data[MaxSize];
	int length;
}SqList;

void InitList(SqList* L) {
	int i;
	for (i = 0; i < MaxSize; i++) {
		L->data[i] = 0;
	}
	L->length = 0;
}

int main() {

	SqList L;
	SqList qw;
	int i;
	InitList(&L);
	for (i = 0; i < MaxSize; i++) {
		printf("data[%d]=%d\n", i, L.data[i]);
	}
	return 0;


}
