#include"mian.h"

bool InitString(HString* H) {
	(*H).length = 0;
	return true;
}

bool SubString(HString* Sub, HString H, int pos, int len) {
	if (pos + len - 1 > H.length)
		return false;
	int i = 0;
	for (i = pos; i < pos + len; i++) {
		(*Sub).ch[i - pos + 1] = H.ch[i];
	}
	(*Sub).length = len;
	return true;
}

int StrCompare(HString S, HString T) {
	for (int i = 0; i <= S.length && i <= T.length; i++) {
		/*if (S.ch[i] > T.ch[i])
			return true;�����ҵ����� ����������ʵ���鷳�� ����������*/
		if (S.ch[i] != T.ch[i])
			return S.ch[i] - T.ch[i];
	}
	return S.length - T.length;
}

//int Index(HString S, HString T) {
//	int j ;
//	int temp;
//	int number = 0;
//	for (int i = 1; i <= S.length;i++) {
//		temp = i;
//		for (j = 1; j <= T.length; j++) {
//			if (T.ch[j] == S.ch[temp]) {
//				temp++;
//				number++;
//				if (number == T.length)
//					return i;
//			}
//		}
//	}
//	return 0;
//}
//����Ϊ���Լ���ʵ�֣�������Ϊ�鱾�ϵ�ʵ�ַ�ʽ ��������ģʽƥ���㷨��ѧϰ����֪���ҵ����ֽⷨ���ǲ�ʹ�û�������������ʹ�÷�����

int Index(HString S, HString T) {
	int i = 1, n = S.length, m = T.length;
	HString sub;
	while (i <= n - m + 1) {
		SubString(&sub, S, i, m);
		if (StrCompare(sub, T) != 0) i++;
		else
			return i;
	}
	return 0;
}

int main() {
	HString H, Sub;
	InitString(&H);
	InitString(&Sub);
	H.ch[1] = 'w';
	H.ch[2] = 'o';
	H.ch[3] = 'a';
	H.ch[4] = 'i';
	H.length = 4;//woai
	SubString(&Sub, H, 3, 2);
	printf("%c\n", Sub.ch[1]);
	printf("%c\n", Sub.ch[2]);
	int j = StrCompare(H, Sub);
	if (j)
		printf("H�ַ�����\n");
	else
		printf("Sub�ַ�������\n");
	printf("Sub��H��λ��Ϊ��%d\n", Index(H, Sub));
	return 0;
}