#include <stdio.h>

int main()
{
    int N, M, K, i, j, x, y, Ans;
    char Map[2000][2000];
    scanf("%d %d %d", &N, &M, &K);
    for(i=0; i<N; ++i)
    {
        scanf("%s", Map[i]);
    }
    for(j=0; j<M; ++j)
    {
        Ans = 0;
        for(i=1; i<N; ++i)
        {
            x = i;
            y = j+i;
            if(x>=0 && x<N && y>=0 && y<M && Map[x][y]=='L')
            {
                ++Ans;
            }
            x = i;
            y = j-i;
            if(x>=0 && x<N && y>=0 && y<M && Map[x][y]=='R')
            {
                ++Ans;
            }
            x = i+i;
            y = j;
            if(x>=0 && x<N && y>=0 && y<M && Map[x][y]=='U')
            {
                ++Ans;
            }
        }
        printf("%d ", Ans);
    }
    return 0;
}
