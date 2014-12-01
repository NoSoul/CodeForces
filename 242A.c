#include <stdio.h>

int Ans[6001][2];

int main()
{
    int x, y, a, b, i, j, Cnt;
    scanf("%d %d %d %d", &x, &y, &a, &b);
    for(Cnt = 0, i = a; i <= x; ++i)
    {
        for(j = b; j < i && j <= y; ++j)
        {
            Ans[Cnt][0] = i;
            Ans[Cnt++][1] = j;
        }
    }
    printf("%d\n", Cnt);
    for(i = 0; i < Cnt; ++i)
    {
        printf("%d %d\n", Ans[i][0], Ans[i][1]);
    }
    return 0;
}
