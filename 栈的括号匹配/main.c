#include"main.h"//自调用头文件时须使用""，并且最好使用自调用头文件，避免出现函数调用函数但被调用的函数未声明的情况

//初始化一个栈
bool InitStack(SqSTACK* S) {
	//头结点指向空
	*S = NULL;//无头结点的栈在使用时更为便利，所以大部分的栈都使用无头结点的链表
	return true;
}

//入栈操作
bool PutStack(SqSTACK* S, char x) {// 传入的是S的地址以及想要传入的元素
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
		printf("恭喜！全部都匹配成功！没有单身！\n");
	else
		printf("Aoooo，有小朋友一个人哎....\n");
	return 0;
}
/*
左括号 


*/