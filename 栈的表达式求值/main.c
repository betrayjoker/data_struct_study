//���Ը�ϲ��Ӧ�������ĺ�׺���ʽ����׺��a+b-c*d ��׺��ab+cd*- ǰ׺��-+ab*cd
//((15/(7-(1+1)))*3 -(2+(1+1))   ��׺��15 7 1 1+-/ 3 * 2 1 1 + + -     A B C D - * E F/ - +
//������׺���ʽת��׺���ʽ��������׺���ʽ��ֵ
#include"main.h"

bool InitStack(SqSTACK* S) {
	*S = NULL;
	return true;
}

bool PutStack(SqSTACK* S, char x) {// 0 1 
	Sqstack* p = (Sqstack*)malloc(sizeof(Sqstack));
	if (p == NULL)
		return false;
	p->data = x;
	p->next = NULL;
	p->next = *S;
	*S = p;
	return true;
}

bool PopStack(SqSTACK* S, char* x) {
	if (*S == NULL)
		return false;
	*x = (*S)->data;
	(*S) = (*S)->next;
	return true;
}

bool Empty(SqSTACK S) {
	if (S == NULL)
		return true;
	return false;
}

int Len(char *PN) {
	int count = 0;
	int i = 0;
	while (PN[i] != 'q') {
		count++;
		i++;
	}
	return count;
}

char* GetElem() {
	int i;
	char x;
	printf("��������ʽ�ӵĴ�Ŵ�С��\n");
	scanf("%d", &i);
	char* PN;
	PN = (char*)malloc(sizeof(char) * i);
	if (PN == NULL)
		printf("�ڴ�����ʧ�ܣ�\n");
	getchar();
	printf("����ɹ�������������ʽ�ӣ�\n");
	scanf("%c", &x);
	i = 0;
	while (x != 'q') {
		PN[i++] = x;
		scanf(" %c", &x);
	}
	PN[i] = x;
	return PN;
}

bool ToRPN(char *PN, SqSTACK* result) {//((15/(7-(1+1)))*3 -(2+(1+1)) 
	Sqstack* temp = (Sqstack*)malloc(sizeof(Sqstack));
	if (temp == NULL)
		return false;
	int i;
	for (i = 0; i < Len(PN); i++) {
	}

}

int main() {
	char* PN;
	PN  = GetElem();
	SqSTACK RPN_result = (Sqstack*)malloc(sizeof(Sqstack));
	if (RPN_result == NULL)
		printf("�ڴ�����ʧ�ܣ�\n");
	InitStack(&RPN_result);
	ToRPN(PN, &RPN_result);



	int i = 0;
	printf("\n%d\n", Len(PN));
	for (i = 0; i < Len(PN); i++) {
		printf("%c   ", PN[i]);
	}
	return 0;
}
