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

bool PreOrder(Tree T) {//��������ȸ��������
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
//		temp++;//���Ǵ���� �����ĸ�����ָ����ƣ��õ�����ָ�������ָ��ָ��ĵ�ַ���ƣ������޷�ʹ���Һ��ӷ����仯���޷��γ������ֽṹ���͡�����дһ�����ķ��������ǲ��Եġ�
//	}
//	return true;
//}

bool LevelOrder(Tree T) {
	LinkQueue Q;
	InitQue(&Q);//���г�ʼ��
	TreeNode* p;
	EnQueue(&Q, T);//����ָ�����
	while (isEmpty(Q)) {
		DeQueue(&Q, &p);//���г���Ԫ��
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