#include <stdio.h>

int main()
{
    int N, V, i, j, K, Num, Cnt = 0;
    char Visit[50] = {0};
    scanf("%d %d", &N, &V);
    for(i=0; i<N; ++i)
    {
        scanf("%d", &K);
        for(j=0; j<K; ++j)
        {
            scanf("%d", &Num);
            if(V > Num)
            {
                Visit[i] = 1;
            }
        }
        if(Visit[i])
        {
            ++Cnt;
        }
    }
    printf("%d\n", Cnt);
    for(i=0; i<N; ++i)
    {
        if(Visit[i])
        {
            printf("%d ", i+1);
        }
    }
    return 0;
}
