#include"main.h"

bool SubString(SString* sub, SString S, int pos, int lenth) {
	if (S.length < pos + lenth - 1)
		return false;
	for (int i = pos; i < pos + lenth; i++) {
		(*sub).data[i - pos + 1] = S.data[i];
	}
	(*sub).length = lenth;
	return true;
}

int StrCompare(SString S, SString T) {
	for (int i = 1; i <= S.length && i <= T.length; i++) {
		if (S.data[i] != T.data[i])
			return S.data[i] - T.data[i];
	}
	return S.length - T.length;
}

int Index(SString S, SString T) {
	int i = 0;
	SString sub;
	while (i <= S.length - T.length + 1) {
		SubString(&sub, S, i, T.length);
		if (StrCompare(sub, T) != 0)
			i++;
		else
			return i;
	}
	return 0;
}

int main() {
	return 0;
}