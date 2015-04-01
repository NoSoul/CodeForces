#include <stdio.h>

int main()
{
    int N, D, i, M, Pre, Ans = 0;
    scanf("%d %d", &N, &D);
    for(i = 0; i < N; ++i)
    {
        scanf("%d", &M);
        if(i)
        {
            if(M <= Pre)
            {
                int Cur = (Pre - M) / D + 1;
                Ans += Cur;
                M += Cur * D;
            }
        }
        Pre = M;
    }
    printf("%d\n", Ans);
    return 0;
}
