#include <stdio.h>

int Judge(int num, int n, int k)
{
    int res = 0;
    while(n--)
    {
        res += num&1;
        num >>= 1;
    }
    return res <= k;
}

int main()
{
    int N, M, K, i, Ans;
    int A[1001];
    scanf("%d %d %d", &N, &M, &K);
    for(i=0; i<=M; ++i)
    {
        scanf("%d", &A[i]);
    }
    Ans = 0;
    for(i=0; i<M; ++i)
    {
        int num = A[i]^A[M];
        if(Judge(num, N, K))
        {
            ++Ans;
        }
    }
    printf("%d\n", Ans);
    return 0;
}
