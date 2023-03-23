#include"main.h"
//Queue First In First Out(FIFO)

bool InitQueue(SqQueue* Q) {
	(*Q).front = 0;
	(*Q).rear = 0;
	return true;
}
bool Empty(SqQueue Q) {
	if (Q.front == Q.rear)
		return true;
	return false;
}
bool DestroyQueue(SqQueue* Q) {
	if (Empty!=1) {
		(*Q).front = (*Q).rear;
	}
	return true;
}
bool EnQueue(SqQueue* Q, int x) {// 0 1 2 3 4 5 6 7 8 9
	if (((*Q).rear + 1) % MaxSize == (*Q).front)
		return false;
	(*Q).data[(*Q).rear] = x;
	(*Q).rear = ((*Q).rear + 1) % MaxSize;
	return true;
}
bool DeQueue(SqQueue* Q,int* x) {
	if (Empty(*Q))
		return false;
	*x = (*Q).data[(*Q).front];
	(*Q).front = ((*Q).front + 1) % MaxSize;
	return true;
}
bool GetHead(SqQueue Q, int* x) {
	if (Empty(Q))
		return false;
	*x = (Q).data[(Q).front];
	return true;
}
bool Full(SqQueue Q) {
	if ((Q.rear + 1) % MaxSize == Q.front)
		return true;
	return false;
}
int main() {
	SqQueue Q;
	InitQueue(&Q);
	if (Empty(Q))
		printf("为空\n");
	else
		printf("不为空\n");
	EnQueue(&Q, 23);
	int x;
	GetHead(Q, &x);
	printf("%d\n",x);
	if (Empty(Q))
		printf("为空\n");
	else
		printf("不为空\n");
	DestroyQueue(&Q);
	printf("%d\n", x);
	if (Empty(Q))
		printf("为空\n");
	else
		printf("不为空\n");
	return 0;
}