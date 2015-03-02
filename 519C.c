#include <stdio.h>

int main()
{
    int N, M, i, Ans, Cur;
    Ans = 0;
    scanf("%d %d", &N, &M);
    for(i = 0; i <= N && 2 * i <= M; ++i)
    {
        Cur = i;
        Cur += (N - i) / 2 < M - 2 * i ? (N - i) / 2 : M - 2 * i;
        if(Cur > Ans)
        {
            Ans = Cur;
        }
    }
    printf("%d\n", Ans);
    return 0;
}
