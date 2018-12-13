#include <stdio.h>

typedef struct {
    int a;
    int b;
} Node_t;
Node_t A[100001];
int Stack[100001];
int Size, StackTop;
char Flag[200001];

int main()
{
    int n, k;
    char str[200001];
    scanf("%d %d %s", &n, &k, &str);
    for(int i = 0; i < n; ++i) {
        if(str[i] == '(') {
            Stack[StackTop++] = i;
        } else {
            --StackTop;
            A[Size].a = Stack[StackTop];
            A[Size++].b = i;
        }
    }
    int m = (n - k) / 2;
    for(int i = 0; i < m; ++i) {
        Flag[A[i].a] = 1;
        Flag[A[i].b] = 1;
    }
    for(int i = 0; str[i]; ++i) {
        if(!Flag[i]) {
            putchar(str[i]);
        }
    }
    return 0;
}
