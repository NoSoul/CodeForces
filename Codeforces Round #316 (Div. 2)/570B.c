#include <stdio.h>

int main()
{
    int N, M, A, B;
    scanf("%d %d", &N, &M);
    A = M - 1;
    B = N - M;
    int Ans = A >= B ? M - 1 : M + 1;
    if(Ans < 1) {
        Ans = 1;
    }
    printf("%d\n", Ans);
    return 0;
}
