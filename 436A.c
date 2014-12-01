#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int t, h, m;
} Candies_t;
Candies_t List[2000];
char Visit[2000];

int cmp(const void *a, const void *b)
{
    return (*(Candies_t *)b).m - (*(Candies_t *)a).m;
}

int Fun(int X, int Pre, int N)
{
    int res, i;
    res = 0;
    memset(Visit, 0, sizeof(Visit));
    while(1)
    {
        for(i = 0; i < N; ++i)
        {
            if(Visit[i] == 0 && List[i].h <= X && List[i].t != Pre)
            {
                Visit[i] = 1;
                Pre ^= 1;
                X += List[i].m;
                ++res;
                break;
            }
        }
        if(i == N)
        {
            break;
        }
    }
    return res;
}

int main()
{
    int N, X, i, Now, Ans;
    scanf("%d %d", &N, &X);
    for(i = 0; i < N; ++i)
    {
        scanf("%d %d %d", &List[i].t, &List[i].h, &List[i].m);
    }
    qsort(List, N, sizeof(Candies_t), cmp);
    Ans = Fun(X, 0, N);
    Now = Fun(X, 1, N);
    if(Now > Ans)
    {
        Ans = Now;
    }
    printf("%d\n", Ans);
    return 0;
}
