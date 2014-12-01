#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int a, b;
} Card;
Card C[1000];

int cmp(const void *a, const void *b)
{
    if((*(Card *)b).b == (*(Card *)a).b)
    {
        return (*(Card *)b).a - (*(Card *)a).a;
    }
    return (*(Card *)b).b - (*(Card *)a).b;
}

int main()
{
    int N, i, Cnt, Ans;
    scanf("%d", &N);
    for(i = 0; i < N; ++i)
    {
        scanf("%d %d", &C[i].a, &C[i].b);
    }
    qsort(C, N, sizeof(Card), cmp);
    for(Cnt = 1, Ans = i = 0; i < N && Cnt > 0; ++i)
    {
        Ans += C[i].a;
        Cnt += C[i].b - 1;
    }
    printf("%d\n", Ans);
    return 0;
}
