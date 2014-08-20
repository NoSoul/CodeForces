#include <stdio.h>

#define MAXN    100001

typedef struct
{
    int min, max;
    int len;
} Seg_t;
Seg_t Seg[MAXN];
int Size;
int A[MAXN];

int JudgeTwo(int idx)
{
    if(Seg[idx].len==1 || Seg[idx+1].len==1)
    {
        return 1;
    }
    if(A[Seg[idx+1].min]-1>A[Seg[idx].max-1] || A[Seg[idx].max]+1<A[Seg[idx+1].min+1])
    {
        return 1;
    }
    return 0;
}

int JudgeThree(int idx)
{
    if(Seg[idx].len != 1)
    {
        return 0;
    }
    if(A[Seg[idx+1].min] - A[Seg[idx-1].max] >= 2)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int N, i, Ans = 0;
    scanf("%d", &N);
    for(i=0; i<N; ++i)
    {
        scanf("%d", &A[i]);
    }
    Size = 0;
    Seg[Size].min = 0;
    Seg[Size].max = 0;
    Seg[Size].len = 1;
    for(i=1; i<N; ++i)
    {
        if(A[i] > A[i-1])
        {
            Seg[Size].max = i;
            ++Seg[Size].len;
        }
        else
        {
            ++Size;
            Seg[Size].min = i;
            Seg[Size].max = i;
            Seg[Size].len = 1;
        }
    }
    if(Size == 0)
    {
        printf("%d\n", N);
    }
    else
    {
        for(i=0; i<=Size; ++i)
        {
            if(Seg[i].len+1 > Ans)
            {
                Ans = Seg[i].len+1;
            }
            if(i!=Size)
            {
                if(JudgeTwo(i))
                {
                    if(Seg[i].len+Seg[i+1].len > Ans)
                    {
                        Ans = Seg[i].len+Seg[i+1].len;
                    }
                }
            }
            if(i!=0)
            {
                if(JudgeThree(i))
                {
                    if(Seg[i-1].len+Seg[i].len+Seg[i+1].len > Ans)
                    {
                        Ans = Seg[i-1].len+Seg[i].len+Seg[i+1].len;
                    }
                }
            }
        }
        printf("%d\n", Ans);
    }
    return 0;
}
