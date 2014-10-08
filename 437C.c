#include <stdio.h>

int main()
{
    int Data[1001];
    int N, M, i, j, Ans = 0;
    scanf("%d %d", &N, &M);
    for(i=1; i<=N; ++i)
    {
        scanf("%d", &Data[i]);
    }
    while(M--)
    {
        scanf("%d %d", &i, &j);
        Ans += Data[i]>Data[j]?Data[j]:Data[i];
    }
    printf("%d\n", Ans);
    return 0;
}
