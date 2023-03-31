#include"main.h"

bool visit(BiTree T) {
	printf("%d\n", T->data.value);
	return true;
}
bool PreOrder(BiTree T) {
	if (T != NULL) {
		visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
	return true;
}

int treeDepth(BiTree T) {
	if (T == NULL)
		return 0;
	else {
		int l = treeDepth(T->lchild);
		int r = treeDepth(T->rchild);
		return l > r ? l + 1 : r + 1;
	}
}
int main() {
	BiTree root = NULL;
	root = (BiTNode*)malloc(sizeof(BiTNode));
	if (root == NULL) {
		printf("�ڴ�����ʧ�ܣ�\n");
		return 0;
	}
	root->lchild = NULL;
	root->rchild = NULL;
	//root->parent = NULL;
	root->data.value = 1;

	return 0;
}

//   ���� -+a*b-cd/ef