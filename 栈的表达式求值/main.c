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

int Len(char* PN) {
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

bool bracketcheck(char* str, int length) {//�ж������Ƿ���Բ���
	Sqstack* s;//�½�һ���洢char���͵�ջ������������[{(���룬����������]})����ȡ��ջ���������ſ��Ƿ�����������ԣ���Ծ�ok������Է���false
	InitStack(&s);//��ʼ��ջ
	for (int i = 0; i < length; i++) {//����������ŵ�����
		if (str[i] == '(' || str[i] == '{' || str[i] == '[') {//�����Ŵ���ջ
			PutStack(&s, str[i]);
		}
		else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
			if (Empty(s))//����������ŵ���ջ�գ�����Ȼ�����
				return false;
			char topElem;
			PopStack(&s, &topElem);//ջ����ȡջ��Ԫ��
			//����Է��ش���
			if (str[i] == '(' && topElem != ')')
				return false;
			if (str[i] == '{' && topElem != '}')
				return false;
			if (str[i] == '{' && topElem != '}')
				return false;
		}
	}
	return Empty(s);//������ȡ�����ջ�л���������ʣ�࣬Ҳ��ƥ�䣬����false
}

int IfOp(char x) {
	switch (x) {
	case'+':
	case'-':
	case'*':
	case'/':
	case'(':
	case')':
	case'%':return 1;
	default:return 0;
	}
}

bool CompareOp(char a, char b) {
	switch (a) {
	case'+':
		if (b == '-') return 1;
		if (b == '+')return 1;
		if (b == '*') return 0;
		if (b == '/')return 0;
		if (b == '(') return 0;
		if (b == ')')return 0;
		if (b == "%")return 0;
	case'-':
		if (b == '-') return 1;
		if (b == '+')return 1;
		if (b == '*') return 0;
		if (b == '/')return 0;
		if (b == '(') return 0;
		if (b == ')')return 0;
		if (b == "%")return 0;
	case'*':
		if (b == '-') return 1;
		if (b == '+')return 1;
		if (b == '*') return 1;
		if (b == '/')return 1;
		if (b == '(') return 0;
		if (b == ')')return 0;
		if (b == "%")return 1;
	case'/':
		if (b == '-') return 1;
		if (b == '+')return 1;
		if (b == '*') return 1;
		if (b == '/')return 1;
		if (b == '(') return 0;
		if (b == ')')return 0;
		if (b == "%")return 1;
	case'%':
		if (b == '-') return 1;
		if (b == '+')return 1;
		if (b == '*') return 1;
		if (b == '/')return 1;
		if (b == '(') return 0;
		if (b == ')')return 0;
		if (b == "%")return 1;
	case'(':
		if (b == '-') return 1;
		if (b == '+')return 1;
		if (b == '*') return 1;
		if (b == '/')return 1;
		if (b == '(') return 1;
		if (b == ')')return 0;
		if (b == "%")return 1;
	case')':
		if (b == '-') return 1;
		if (b == '+')return 1;
		if (b == '*') return 1;
		if (b == '/')return 1;
		if (b == '(') return 1;
		if (b == ')')return 1;
		if (b == "%")return 1;
	}
}

bool OutputStack(SqSTACK S) {
	if (S == NULL)
		return false;
	while (S != NULL) {
		printf("%c ", S->data);
		S = S->next;
	}
	printf("\n");
	return true;
}

int LengthStack(SqSTACK S) {
	int count = 0;
	while (S != NULL) {
		count++;
		S = S->next;
	}
	return count;
}

bool RoutPutStack(SqSTACK S) {
	if (S == NULL)
		return false;
	char* temp = (char*)malloc(sizeof(char) * LengthStack(S));
	int i = 0;
	while (S != NULL) {
		temp[i] = S->data;
		i++;
		S = S->next;
	}
	for (i = i-1; i >=0; i--) {
		printf("%c ", temp[i]);
	}
	printf("\n");
	return true;
}

bool ToRPN(char* PN, SqSTACK* result) {//((15/(7-(1+1)))*3 -(2+(1+1)))��PNָ�����
	Sqstack* temp = (Sqstack*)malloc(sizeof(Sqstack));
	if (temp == NULL)
		return false;
	InitStack(&temp);
	int i, len, number = 0;//��number��������Ĵ���10����
	char x;//�ݴ�����
	len = Len(PN);
	for (i = 0; i < len; i++) {// 1+2+3
		if (IfOp(PN[i])) {//�ַ����ж�
			if (Empty(temp)) {
				PutStack(&temp, PN[i]);
				continue;
			}	
			switch (PN[i]) {
			case'(':PutStack(&temp, PN[i]);//������ֱ�ӽ�ջ
			case')'://���������ջ��Ԫ�������ջ��ֱ������������Ϊֹ����ɾ��������
				while (temp->data != '(') {
					PutStack(result, temp->data);
					temp = temp->next;
				}
				temp = temp->next;
			default:
				if (temp->data != '(') {//// + + + + + 
					while (CompareOp(temp->data, PN[i])) {
						PutStack(result, PN[i]);
						temp = temp->next;
						if (temp == NULL)
							break;
					}
					PutStack(&temp, PN[i]);
				}
			}
			number = 0;
		}
		else {//���ַ�ֱ����ջ
			x = PN[i];//������һ������ ������ô�ô���10�����ִ������
			/*if (number == 1) {
				PopStack(result, &x);
				x = (char)((int)x * 10 + (int)x);
			}*/
			PutStack(result, x);
			number = 1;
		}
	}
	if (temp != NULL) {
		PutStack(result, temp->data);
		temp = temp->next;
	}
	return true;
}

int main() {
	//�½�һ��ָ�벢ʹ��GetElem������̬���顢��ȡ�û�����ı��ʽ
	char* PN;
	PN = GetElem();

	//�ж��û����ʽ�е������Ƿ�ƥ��
	if (bracketcheck(PN, Len(PN)))
		printf("����ƥ��ɹ���\n\n");
	else {
		printf("����ƥ��ʧ�ܣ�����������Ų�ƥ�䣡\n");
		return 0;
	}

	//�½���׺���ʽת����ɺ�������
	SqSTACK RPN_result = (Sqstack*)malloc(sizeof(Sqstack));
	if (RPN_result == NULL)
		printf("�ڴ�����ʧ�ܣ�\n");

	//�����ʼ��
	InitStack(&RPN_result);

	//����û��������׺���ʽ
	int i = 0;
	//printf("\n%d\n", Len(PN));
	printf("������ı��ʽΪ:\n");
	for (i = 0; i < Len(PN); i++) {
		printf("%c", PN[i]);
	}
	printf("\n");

	//�û��������׺���ʽת��׺
	ToRPN(PN, &RPN_result);

	//�����׺���ʽ������ʱΪ����
	OutputStack(RPN_result);

	//�������RPN_result��Ԫ�أ�����׺���ʽ
	RoutPutStack(RPN_result);




	return 0;
}
