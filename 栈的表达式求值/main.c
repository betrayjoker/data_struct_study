//考试更喜欢应用面更广的后缀表达式。中缀：a+b-c*d 后缀：ab+cd*- 前缀：-+ab*cd
//((15/(7-(1+1)))*3 -(2+(1+1))   后缀：15 7 1 1+-/ 3 * 2 1 1 + + -     A B C D - * E F/ - +
//下求中缀表达式转后缀表达式，并将后缀表达式求值
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
	printf("请输入您式子的大概大小：\n");
	scanf("%d", &i);
	char* PN;
	PN = (char*)malloc(sizeof(char) * i);
	if (PN == NULL)
		printf("内存申请失败！\n");
	getchar();
	printf("申请成功！请输入您的式子！\n");
	scanf("%c", &x);
	i = 0;
	while (x != 'q') {
		PN[i++] = x;
		scanf(" %c", &x);
	}
	PN[i] = x;
	return PN;
}

bool bracketcheck(char* str, int length) {//判断括号是否配对操作
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
			if (str[i] == '{' && topElem != '}')
				return false;
		}
	}
	return Empty(s);//右括号取完如果栈中还有左括号剩余，也不匹配，返回false
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

bool ToRPN(char* PN, SqSTACK* result) {//((15/(7-(1+1)))*3 -(2+(1+1)))由PN指针承载
	Sqstack* temp = (Sqstack*)malloc(sizeof(Sqstack));
	if (temp == NULL)
		return false;
	InitStack(&temp);
	int i, len, number = 0;//用number控制输入的大于10的数
	char x;//暂存数据
	len = Len(PN);
	for (i = 0; i < len; i++) {// 1+2+3
		if (IfOp(PN[i])) {//字符需判断
			if (Empty(temp)) {
				PutStack(&temp, PN[i]);
				continue;
			}	
			switch (PN[i]) {
			case'(':PutStack(&temp, PN[i]);//左括号直接进栈
			case')'://右括号输出栈中元素至结果栈，直到遇到左括号为止，并删除左括号
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
		else {//非字符直接入栈
			x = PN[i];//这里有一个问题 就是怎么让大于10的数字存放起来
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
	//新建一个指针并使用GetElem构建动态数组、获取用户输入的表达式
	char* PN;
	PN = GetElem();

	//判断用户表达式中的括号是否匹配
	if (bracketcheck(PN, Len(PN)))
		printf("括号匹配成功！\n\n");
	else {
		printf("括号匹配失败！您输入的括号不匹配！\n");
		return 0;
	}

	//新建后缀表达式转换完成后结果链表
	SqSTACK RPN_result = (Sqstack*)malloc(sizeof(Sqstack));
	if (RPN_result == NULL)
		printf("内存申请失败！\n");

	//链表初始化
	InitStack(&RPN_result);

	//输出用户输入的中缀表达式
	int i = 0;
	//printf("\n%d\n", Len(PN));
	printf("您输入的表达式为:\n");
	for (i = 0; i < Len(PN); i++) {
		printf("%c", PN[i]);
	}
	printf("\n");

	//用户输入的中缀表达式转后缀
	ToRPN(PN, &RPN_result);

	//输出后缀表达式，但此时为倒序
	OutputStack(RPN_result);

	//倒着输出RPN_result中元素，即后缀表达式
	RoutPutStack(RPN_result);




	return 0;
}
