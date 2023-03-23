#include <stdio.h>

typedef enum{false,true}bool;

void achange(int a) {
	a = 5;
}

int main() {
	int* p,*q;
	int a = 2234;
	int b = 12;
	p = &a;
	q = p;
	p = &b;
	printf("%d   %d", *p,*q);
}