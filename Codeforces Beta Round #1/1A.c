#include <stdio.h>

int main()
{
    __int64 N, M, A;
    while(scanf("%I64d %I64d %I64d", &N, &M, &A) != EOF) {
        if(N % A) {
            N += A - N % A;
        }
        if(M % A) {
            M += A - M % A;
        }
        printf("%I64d\n", N / A * M / A);
    }
    return 0;
}
