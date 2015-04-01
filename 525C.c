#include <stdio.h>
#include <stdlib.h>

#define MAXN    100001

typedef struct
{
    int l;
    int cnt;
    int fixcnt;
} Node_t;
Node_t After[MAXN];
int L[MAXN];
int Size;

int cmp(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}

int main()
{
    int N, i;
    int Rect[2];
    long long Ans = 0;
    scanf("%d", &N);
    for(i = 0; i < N; ++i)
    {
        scanf("%d", &L[i]);
    }
    qsort(L, N, sizeof(int), cmp);
    for(i = 0; i < N; ++i)
    {
        if(Size == 0 || L[i] != After[Size - 1].l)
        {
            After[Size].l = L[i];
            After[Size].cnt = 1;
            After[Size].fixcnt = 0;
            ++Size;
        }
        else
        {
            ++After[Size - 1].cnt;
        }
    }
    Rect[0] = Rect[1] = 0;
    int Idx = 0;
    for(i = 0; i < N; ++i)
    {
        while(After[i].cnt >= 2)
        {
            Rect[Idx] = After[i].l;
            if(++Idx == 2)
            {
                Ans += (long long)Rect[0] * Rect[1];
                Rect[0] = Rect[1] = 0;
                Idx = 0;
            }
            int target = 2;
            if(After[i].fixcnt)
            {
                if(After[i].fixcnt >= target)
                {
                    After[i].cnt -= target;
                    After[i].fixcnt -= target;
                    target = 0;
                }
                else
                {
                    After[i].cnt -= After[i].fixcnt;
                    target -= After[i].fixcnt;
                    After[i].fixcnt = 0;
                }
            }
            if(target)
            {
                After[i].cnt -= target;
            }
        }
        if(After[i].cnt == 1)
        {
            if(i != N - 1 && After[i].l - 1 == After[i + 1].l)
            {
                ++After[i + 1].cnt;
                ++After[i + 1].fixcnt;
            }
        }
    }
    printf("%I64d\n", Ans);
    return 0;
}
