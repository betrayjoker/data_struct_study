#include"main.h"

bool Initial(int S[]) {
	for (int i = 0; i < SIZE; i++) {
		S[i] = -1;
	}
	return true;
}

int Find(int S[], int x) {
	while (S[x] >= 0)
		x = S[x];
	return x;
}

bool Union(int S[], int root1, int root2) {
	if (root1 == root2)
		return false;
	if (S[root1] > S[root2]) {//root2½áµã¶à
		S[root2] = +S[root1];
		S[root1] = root2;
	}
	else {
		S[root1] = +S[root2];
		S[root2] = root1;
	}
	return true;
}


int main() {
	int s[SIZE];
	Initial(s);
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", s[i]);
	}
	return 0;
}