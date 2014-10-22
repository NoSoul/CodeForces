#include <stdio.h>

int main()
{
    int N, i, j, Cnt;
    char AllR, AllC;
    char Map[100][101];
    int Ans[101][2];
    scanf("%d", &N);
    for(i=0; i<N; ++i)
    {
        scanf("%s", Map[i]);
    }
    Cnt = 0;
    for(i=0; i<N; ++i)
    {
        for(j=0; j<N; ++j)
        {
            if(Map[i][j]=='.')
            {
                Ans[Cnt][0] = i;
                Ans[Cnt++][1] = j;
                break;
            }
        }
    }
    if(Cnt != N)
    {
        Cnt = 0;
        for(j=0; j<N; ++j)
        {
            for(i=0; i<N; ++i)
            {
                if(Map[i][j]=='.')
                {
                    Ans[Cnt][0] = i;
                    Ans[Cnt++][1] = j;
                    break;
                }
            }
        }
        if(Cnt != N)
        {
            puts("-1");
            return 0;
        }
    }
    for(i=0; i<Cnt; ++i)
    {
        printf("%d %d\n", Ans[i][0]+1, Ans[i][1]+1);
    }
    return 0;
}
