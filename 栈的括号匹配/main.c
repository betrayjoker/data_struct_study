#include"main.h"//�Ե���ͷ�ļ�ʱ��ʹ��""���������ʹ���Ե���ͷ�ļ���������ֺ������ú����������õĺ���δ���������

//��ʼ��һ��ջ
bool InitStack(SqSTACK* S) {
	//ͷ���ָ���
	*S = NULL;//��ͷ����ջ��ʹ��ʱ��Ϊ���������Դ󲿷ֵ�ջ��ʹ����ͷ��������
	return true;
}

//��ջ����
bool PutStack(SqSTACK* S, char x) {// �������S�ĵ�ַ�Լ���Ҫ�����Ԫ��
	Sqstack* temp = (Sqstack*)malloc(sizeof(Sqstack));
	if (temp == NULL)
		return false;
	temp->data = x;
	temp->next = NULL;
	temp->next = *S;
	*S = temp;
	return true;
}

bool Empty(SqSTACK S) {
	if (S == NULL)
		return true;
	return false;
}

bool PopStack(SqSTACK* S, char* x) {// 5 4 3 2 1
	if (*S == NULL)
		return false;
	*x = (*S)->data;
	*S = (*S)->next;
	return true;
}
bool bracketcheck(char str[], int length) {
	Sqstack* s;
	InitStack(&s);
	for (int i = 0; i < length; i++) {
		if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
			PutStack(&s, str[i]);
		}
		else {
			if (Empty(s))
				return false;
			char topElem;
			PopStack(&s, &topElem);
			if (str[i] == '(' && topElem != ')')
				return false;
			if (str[i] == '{' && topElem != '}')
				return false;
			if (str[i] == '{' && topElem !='}')
				return false;
		}
	}
	return Empty(s);
}



int main() {
	char bracket[10] = { '(',')','{','}' ,'['};
	printf("%d\n\n", strlen(bracket));
	if (bracketcheck(bracket,strlen(bracket)))
		printf("��ϲ��ȫ����ƥ��ɹ���û�е���\n");
	else
		printf("Aoooo����С����һ���˰�....\n");
	return 0;
}
/*
������ 


*/