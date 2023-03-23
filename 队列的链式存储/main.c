#include"main.h"

bool InitQueue(LinkQueue* Q) {
	//��ͷ���
	(*Q).rear = (*Q).front = (LinkNode*)malloc(sizeof(LinkNode));
	if ((*Q).rear == NULL)
		return false;
	(*Q).front->next = NULL;
	return true;

	//����ͷ���
	/*(*Q).front = NULL;
	(*Q).rear = NULL;
	return true;*/
}

bool Empty(LinkQueue Q) {//1 2 3 4 5 6 7 8
	//��ͷ���
	if (Q.front == Q.rear)
		return true;
	return false;

	//����ͷ���
	/*if (Q.rear == NULL && Q.front == NULL)
		return true;
	return false;*/
}

bool EnQueue(LinkQueue* Q, int x) {
	//��ͷ���
	/*LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	if (s == NULL)
		return false;
	s->data = x;
	s->next = NULL;
	(*Q).rear->next = s;
	(*Q).rear = s;
	return true;*/

	//����ͷ���
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	if (s == NULL)
		return false;
	s->data = x;
	s->next = NULL;
	if ((*Q).front == NULL) {
		Q->front = s;
		Q->rear = s;
	}
	else {
		Q->rear->next = s;
		Q->rear = s;
	}
	return true;
}

bool DeQueue(LinkQueue* Q, int* x) {
	//��ͷ���
	//if (Q->rear == Q->front)//0 1 2 3 4 5
	//	return false;
	//LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode));
	//p = Q->front->next;
	//*x = p->data;
	//Q->front->next = p->next;
	//if (p == Q->rear) {
	//	Q->rear = Q->front;
	//}
	//free(p);
	//return true;

	//����ͷ��� 1 2 3 4 5   2
	if (Q->front == NULL)
		return false;
	LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode));
	p = Q->front;
	*x = p->data;
	Q->front = p->next;
	if (Q->rear == p) {
		Q->rear = NULL;
		Q->front = NULL;
	}
	free(p);
	return true;

}
int main() {
	LinkQueue Q;
	InitQueue(&Q);
}