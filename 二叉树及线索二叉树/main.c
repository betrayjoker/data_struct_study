#include"main.h"

TreeNode* pre = NULL;

bool InitTree(Tree* T) {
	*T = (TreeNode*)malloc(sizeof(TreeNode));
	if (*T == NULL)
		return false;
	(*T)->ltag = 0;
	(*T)->rtag = 0;
	return true;
}

bool visit(Tree* T) {
	if ((*T)->lchild == NULL) {
		(*T)->lchild = pre;
		(*T)->ltag = 1;
	}
	if (pre != NULL && pre->rchild == NULL) {
		pre->rchild = (*T);
		pre->rtag = 1;
	}
	pre = (*T);
	return true;
}

bool PreOrder(Tree T) {//先序遍历先根后左后右
	if (T != NULL) {
		visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
	return true;
}

//bool PopTree(Tree* T) {
//	char a[] = { '-','+','a',' * ','b','-','c','d','/','e','f' };
//	TreeNode* temp;
//	temp = (TreeNode*)malloc(sizeof(TreeNode));
//	if (temp == NULL)
//		return false;
//	temp = *T;
//	for (int i = 0; i < sizeof(a); i++) {
//		temp->data.value = a[i];
//		temp++;//这是错误的 将树的根结点的指针后移，得到的是指向根结点的指针指向的地址后移，根本无法使左右孩子发生变化，无法形成树这种结构类型。所以写一个树的方法这样是不对的。
//	}
//	return true;
//}

bool LevelOrder(Tree T) {
	LinkQueue Q;
	InitQue(&Q);//队列初始化
	TreeNode* p;
	EnQueue(&Q, T);//队列指针入队
	while (isEmpty(Q)) {
		DeQueue(&Q, &p);//队列出队元素
		visit(p);
		if (p->lchild != NULL) {
			EnQueue(&Q, T->lchild);
		}
		if (p->rchild != NULL) {
			EnQueue(&Q, T->rchild);
		}

	}
}

bool InThread(Tree* T) {
	if (T != NULL) {
		InThread(T);
		visit(T);
		InThread(T);
	}
}
bool CreateInThread(Tree* T) {
	if (T != NULL) {
		InThread(T);
		if (pre->rchild == NULL)
			pre->rtag = 1;
	}
}

int main() {
	Tree T;
	InitTree(&T);
	//PopTree(&T);
	return 0;

}