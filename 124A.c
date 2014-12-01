#include <stdio.h>

int main()
{
    int N, A, B, M;
    scanf("%d %d %d", &N, &A, &B);
    M = (A + 1) > (N - B) ? (A + 1) : (N - B);
    printf("%d\n", N - M + 1);
    return 0;
}
