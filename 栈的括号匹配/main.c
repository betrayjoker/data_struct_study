#include"main.h"//自调用头文件时须使用""，并且最好使用自调用头文件，避免出现函数调用函数但被调用的函数未声明的情况

//初始化一个栈
bool InitStack(SqSTACK* S) {
	//头结点指向空
	*S = NULL;//无头结点的栈在使用时更为便利，所以大部分的栈都使用无头结点的链表
	return true;
}

//入栈操作
bool PutStack(SqSTACK* S, char x) {// 传入的是S的地址以及想要传入的元素
	Sqstack* temp = (Sqstack*)malloc(sizeof(Sqstack));//新建一个结点并为其申请空间
	if (temp == NULL)//判断是否申请空间成功
		return false;
	temp->data = x;//将传入的元素放入申请的空间 1 2 3 4 5
	temp->next = NULL;//先将temp的next指向空，初始化
	temp->next = *S;//栈的插入总头放头出，先进后出（First In Last Out），所以将temp的next指针指向原来的首指针*S构成 temp—>S所指向的存储区域这种形式
	*S = temp;//因为S为头指针，所以将S指向此时链表最前方也就是栈最上方的位置，也就是此时temp指向的位置
	return true;
}

bool Empty(SqSTACK S) {
	if (S == NULL)//无头指针 栈空即是栈头指向空 若为空 返回是（1）；非空 返回否（0）
		return true;
	return false;
}

bool PopStack(SqSTACK* S, char* x) {// 5 4 3 2 1 出栈操作 从链表头也就是栈的最上方拿
	if (*S == NULL)//如果链表是空的，那拿不到，返回错误
		return false;
	*x = (*S)->data;//将栈顶的值传回
	*S = (*S)->next;//将栈首指针指向下一个位置，即在逻辑上舍掉了第一个元素，程序运行结束后，原本的第一个元素所占空间会自动回收
	return true;
}
bool bracketcheck(char str[], int length) {//判断括号是否配对操作
	Sqstack* s;//新建一个存储char类型的栈链表，将左括号[{(放入，碰到右括号]})就提取出栈顶的左括号看是否与右括号配对，配对就ok，不配对返回false
	InitStack(&s);//初始化栈
	for (int i = 0; i < length; i++) {//遍历存放括号的数组
		if (str[i] == '(' || str[i] == '{' || str[i] == '[') {//左括号存入栈
			PutStack(&s, str[i]);
		}
		else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
			if (Empty(s))//如果是右括号但是栈空，则显然不配对
				return false;
			char topElem;
			PopStack(&s, &topElem);//栈不空取栈顶元素
			//不配对返回错误
			if (str[i] == '(' && topElem != ')')
				return false;
			if (str[i] == '{' && topElem != '}')
				return false;
			if (str[i] == '{' && topElem !='}')
				return false;
		}
	}
	return Empty(s);//右括号取完如果栈中还有左括号剩余，也不匹配，返回false
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