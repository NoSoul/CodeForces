#include <stdio.h>

#define MAX(x, y) ((x)>(y)?(x):(y))

long long A[100001];

int main()
{
    int N, i, Num, M;
    long long Ans;
    scanf("%d", &N);
    for(i = 0; i < N; ++i)
    {
        scanf("%d", &Num);
        A[i + 1] = Num;
    }
    scanf("%d", &M);
    while(M--)
    {
        scanf("%d %d", &i, &Num);
        Ans = MAX(A[i], A[1]);
        printf("%I64d\n", Ans);
        A[i] = Ans + Num;
        A[1] = Ans + Num;
    }
    return 0;
}
