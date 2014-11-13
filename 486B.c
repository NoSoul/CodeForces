#include <stdio.h>

int main()
{
    int N, M, i, j, k;
    int Mat[100][100];
    int Map[100][100];
    scanf("%d %d", &M, &N);
    for(i=0; i<M; ++i)
    {
        for(j=0; j<N; ++j)
        {
            scanf("%d", &Mat[i][j]);
            Map[i][j] = 1;
        }
    }
    for(i=0; i<M; ++i)
    {
        for(j=0; j<N; ++j)
        {
            if(Mat[i][j] == 0)
            {
                for(k=0; k<N; ++k)
                {
                    Map[i][k] = 0;
                }
                for(k=0; k<M; ++k)
                {
                    Map[k][j] = 0;
                }
            }
        }
    }
    for(i=0; i<M; ++i)
    {
        for(j=0; j<N; ++j)
        {
            int num = 0;
            for(k=0; k<N; ++k)
            {
                num |= Map[i][k];
            }
            for(k=0; k<M; ++k)
            {
                num |= Map[k][j];
            }
            if(num != Mat[i][j])
            {
                puts("NO");
                return 0;
            }
        }
    }
    puts("YES");
    for(i=0; i<M; ++i)
    {
        for(j=0; j<N; ++j)
        {
            printf("%d ", Map[i][j]);
        }
        puts("");
    }
    return 0;
}
