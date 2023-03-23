#include<stdio.h>
#include<stdlib.h>
#define InitSize 10

typedef struct {
	int* data;
	int MaxSize;
	int length;
}SqList;

typedef enum{false,true}bool;

int GetElem(SqList* L, int i) {
	return L->data[i - 1];
}

int LocateElem(SqList* L, int e) {
	int j = 0;
	for (j = 0; j < L->length; j++) {
		if (L->data[j] == e)//如果是float，int，char这些基本类型，可以直接使用“==”对比，如果是自定义的结构体，那么需要自行写结构体中各个元素相等，不能直接使用“==”。
			return j + 1;
	}
	return 0;
}

void InitList(SqList* L) {
	L->data = (int*)malloc(InitSize * sizeof(int));
	if (L->data == NULL) {
		printf("内存申请失败！\n");
		return 0;
	}
	L->length = 0;
	L->MaxSize = InitSize;
	for (int i = 0; i < L->MaxSize; i++) {
		L->data[i] = 0;
	}
}

void IncreaseSize(SqList* L, int len) {
	int* p = L->data;
	L->data = (int*)malloc((L->MaxSize + len) * sizeof(int));
	if (L->data == NULL) {
		printf("内存申请失败！\n");
		return 0;
	}
	for (int i = 0; i < L->length; i++) {
		L->data[i] = p[i];
	}
	L->MaxSize = L->MaxSize + len;
	free(p);
}

bool ListInsert(SqList* L, int i, int e) {
	if (i<1 || i> L->length + 1)
		return false;
	if (L->length >= L->MaxSize)
		return false;
	for (int j = L->length; j >= i; j--) {
		L->data[j] = L->data[j - 1];
	}
	L->data[i - 1] = e;
	L->length++;
	return true;
}

bool ListDelete(SqList* L, int i,int *e) {
	if (i < 1 || i >= L->length)
		return false;
	*e = L->data[i - 1];
	int j;
	for (j = i; j < L->length; j++) {
		L->data[j-1] = L->data[j];
	}
	L->data[j-1] = '\0';
	L->length--;
	return true;
}

int main() {
	SqList L;
	InitList(&L);
	int e = -1, i;
	L.data[0] = 1;
	L.data[1] = 2;
	L.data[2] = 1;
	L.data[3] = 5;
	L.length = 4;
	for (i = 0; i < L.length; i++) {
		printf("%d ", L.data[i]);
	}
	printf("\n-----------------\n");
	ListInsert(&L, 1, 3);
	for (i = 0; i < L.length; i++) {
		printf("%d ", L.data[i]);
	}
	free(L.data);
	return 0;
}