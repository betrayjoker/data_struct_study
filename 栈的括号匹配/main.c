#include"main.h"//�Ե���ͷ�ļ�ʱ��ʹ��""���������ʹ���Ե���ͷ�ļ���������ֺ������ú����������õĺ���δ���������

//��ʼ��һ��ջ
bool InitStack(SqSTACK* S) {
	//ͷ���ָ���
	*S = NULL;//��ͷ����ջ��ʹ��ʱ��Ϊ���������Դ󲿷ֵ�ջ��ʹ����ͷ��������
	return true;
}

//��ջ����
bool PutStack(SqSTACK* S, char x) {// �������S�ĵ�ַ�Լ���Ҫ�����Ԫ��
	Sqstack* temp = (Sqstack*)malloc(sizeof(Sqstack));//�½�һ����㲢Ϊ������ռ�
	if (temp == NULL)//�ж��Ƿ�����ռ�ɹ�
		return false;
	temp->data = x;//�������Ԫ�ط�������Ŀռ� 1 2 3 4 5
	temp->next = NULL;//�Ƚ�temp��nextָ��գ���ʼ��
	temp->next = *S;//ջ�Ĳ�����ͷ��ͷ�����Ƚ������First In Last Out�������Խ�temp��nextָ��ָ��ԭ������ָ��*S���� temp��>S��ָ��Ĵ洢����������ʽ
	*S = temp;//��ΪSΪͷָ�룬���Խ�Sָ���ʱ������ǰ��Ҳ����ջ���Ϸ���λ�ã�Ҳ���Ǵ�ʱtempָ���λ��
	return true;
}

bool Empty(SqSTACK S) {
	if (S == NULL)//��ͷָ�� ջ�ռ���ջͷָ��� ��Ϊ�� �����ǣ�1�����ǿ� ���ط�0��
		return true;
	return false;
}

bool PopStack(SqSTACK* S, char* x) {// 5 4 3 2 1 ��ջ���� ������ͷҲ����ջ�����Ϸ���
	if (*S == NULL)//��������ǿյģ����ò��������ش���
		return false;
	*x = (*S)->data;//��ջ����ֵ����
	*S = (*S)->next;//��ջ��ָ��ָ����һ��λ�ã������߼�������˵�һ��Ԫ�أ��������н�����ԭ���ĵ�һ��Ԫ����ռ�ռ���Զ�����
	return true;
}
bool bracketcheck(char str[], int length) {//�ж������Ƿ���Բ���
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
			if (str[i] == '{' && topElem !='}')
				return false;
		}
	}
	return Empty(s);//������ȡ�����ջ�л���������ʣ�࣬Ҳ��ƥ�䣬����false
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