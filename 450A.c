#include <stdio.h>

int main()
{
    int N, M, i, Ans, Now, Max;
    int A[100];
    scanf("%d %d", &N, &M);
    Ans = 1;
    Max = 0;
    for(i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
        Now = A[i] / M + ((A[i] % M) ? 1 : 0);
        if(Now >= Max) {
            Max = Now;
            Ans = i + 1;
        }
    }
    printf("%d\n", Ans);
    return 0;
}
