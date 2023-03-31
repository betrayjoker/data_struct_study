#include"main.h"
#define MaxSize 100
bool InitTree(TreeNode* t) {
	for (int i = 0; i < MaxSize; i++) {
		t->isEmpty = true;
	}
	return true;
}
int main() {
	TreeNode t[MaxSize];
	InitTree(t);
	return 0;
}

