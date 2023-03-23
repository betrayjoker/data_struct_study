#include"main.h"
bool InitListnode(Listack* S) {
	//*S = (Listack*)malloc(sizeof(Linknode));
	*S = NULL;
	return true;
}

int Length(Listack S) {
	int len = 0;
	while (S != NULL) {
		S = S->next;
		len++;
	}
	return len;
}

bool Empty(Listack S) {
	if (S == NULL)
		return true;
	return false;
}
bool PushList(Listack* S, int x) {
	Linknode* temp = (Linknode*)malloc(sizeof(Linknode));
	if (temp == NULL)
		return false;
	temp->data = x;
	temp->next = NULL;
	temp->next = (*S);
	(*S) = temp;
	return true;
}

bool GetTopList(Listack S) {
	if (S == NULL)
		return false;
	while (S != NULL) {
		printf("%4d\n", S->data);
		S = S->next;
	}
	return true;
}

bool PutList(Listack* S) {//1 2 3 4 5
	if (*S == NULL)
		return false;
	(*S) = (*S)->next;
	return true;
}
bool ToEmpty(Listack* S) {
	while(*S != NULL) {
		(*S) = (*S)->next;
	}
	return true;
}
int main() {
	Listack S;
	InitListnode(&S);
	printf("%d\n", Length(S));
	if (Empty(S))
		printf("Empty\n");
	else
		printf("UnEmpty\n");
	PushList(&S, 23);
	PushList(&S, 24);
	PushList(&S, 28);
	if (Empty(S))
		printf("Empty\n");
	else
		printf("UnEmpty\n");
	ToEmpty(&S);
	if (Empty(S))
		printf("Empty\n");
	else
		printf("UnEmpty\n");
	GetTopList(S);
	return 0;
}

