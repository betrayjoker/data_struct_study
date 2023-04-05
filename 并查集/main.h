#include<stdio.h>
#define SIZE 13

typedef enum { false, true }bool;

bool Initial(int S[]);

int Find(int S[], int x);

bool Union(int S[], int root1, int root2);