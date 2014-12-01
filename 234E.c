#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char Name[21];
    int  Rating;
    char flag;
} Team;
Team T[65];
int X, A, B, C, Now;

void Get()
{
    Now = (X * A + B) % C;
    X = Now;
    return;
}

int cmp(const void *a, const void *b)
{
    return (*(Team *)b).Rating - (*(Team *)a).Rating;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N, i, M, Case, K, j, k, Cnt;
    scanf("%d %d %d %d %d", &N, &X, &A, &B, &C);
    for(i = 0; i < N; ++i)
    {
        scanf("%s %d", T[i].Name, &T[i].Rating);
    }
    qsort(T, N, sizeof(Team), cmp);
    M = K = N / 4;
    Case = 0;
    while(--M)
    {
        printf("Group %c:\n", 'A' + Case);
        ++Case;
        for(i = 0; i < 4; ++i)
        {
            Get();
            j = Now % (M + 1);
            for(Cnt = -1, k = i * K; k < (i + 1)*K; ++k)
            {
                if(!T[k].flag)
                {
                    ++Cnt;
                    if(Cnt == j)
                    {
                        T[k].flag = 1;
                        printf("%s\n", T[k].Name);
                        break;
                    }
                }
            }
        }
    }
    printf("Group %c:\n", 'A' + Case);
    for(i = 0; i < N; ++i)
    {
        if(!T[i].flag)
        {
            printf("%s\n", T[i].Name);
        }
    }
    return 0;
}
