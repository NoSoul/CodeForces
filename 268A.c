#include <stdio.h>

typedef struct
{
    int a, b;
} Team;
Team T[30];

int main()
{
    int N, i, j, Cnt;
    scanf("%d", &N);
    for(i = 0; i < N; ++i)
    {
        scanf("%d %d", &T[i].a, &T[i].b);
    }
    for(Cnt = i = 0; i < N; ++i)
    {
        for(j = 0; j < N; ++j)
        {
            if(j == i)
            {
                continue;
            }
            Cnt += T[i].a == T[j].b;
        }
    }
    printf("%d\n", Cnt);
    return 0;
}

