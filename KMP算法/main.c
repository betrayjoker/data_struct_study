#include"main.h"

bool SubString(SString* sub, SString S, int pos, int lenth) {
	if (pos + lenth - 1 > S.lenth)
		return false;
	for (int i = pos; i <= pos + lenth; i++) {
		(*sub).data[i - pos + 1] = S.data[i];
	}
	(*sub).lenth = lenth;
	return true;
}

int StrCompare(SString S, SString T) {
	for (int i = 1; i <= S.lenth && i <= T.lenth; i++) {
		if (S.data[i] != T.data[i])
			return S.data[i] - T.data[i];
	}
	return S.lenth - T.lenth;
}

int Index(SString S, SString T) {
	int i = 0;
	SString sub;
	while (i <= S.lenth - T.lenth + 1) {
		SubString(&sub, S, i, T.lenth);
		if (StrCompare(sub, T) != 0)i++;
		else return i;
	}	
	return 0;
}

int Index_KMP(SString S, SString T, int next[]) {
	int i = 1, j = 1;
	while (i <= S.lenth && j <= T.lenth) {
		if (j == 0 || S.data[i] == T.data[j]) {
			i++;
			j++;
		}
		else {
			j = next[j];
		}
	}
	if (j > T.lenth)
		return j - T.lenth;
	else
		return 0;
}
int main() {
	return 0;
}