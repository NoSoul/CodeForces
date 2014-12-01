#include <stdio.h>

#define MAX 30

int Map[MAX][MAX];
int  N;

int Judge(int x, int y)
{
    int R, C, i;
    for(C = R = i = 0; i < N; ++i)
    {
        R += Map[x][i];
        C += Map[i][y];
    }
    return C > R;
}

int main()
{
    int i, j, k;
    scanf("%d", &N);
    for(i = 0; i < N; ++i)
    {
        for(j = 0; j < N; ++j)
        {
            scanf("%d", &Map[i][j]);
        }
    }
    for(k = i = 0; i < N; ++i)
    {
        for(j = 0; j < N; ++j)
        {
            if(Judge(i, j))
            {
                ++k;
            }
        }
    }
    printf("%d\n", k);
    return 0;
}
