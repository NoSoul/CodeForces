#include <stdio.h>

int main()
{
    int A, B, C, N;
    scanf("%d %d %d %d", &A, &B, &C, &N);
    if(A + B - C >= N || C > A || C > B) {
        printf("-1\n");
    } else {
        printf("%d\n", N + C - A - B);
    }
    return 0;
}
