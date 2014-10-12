#include <stdio.h>

#define MAXN    200000
typedef long long LL_t;
LL_t Ans;
int A[MAXN];

int main()
{
    int N, i, LeftNum, RightNum, LeftIdx, RightIdx;
    scanf("%d", &N);
    LeftNum = 0;
    RightNum = 0;
    for(i=0; i<N; ++i)
    {
        scanf("%d", &A[i]);
        if(A[i])
        {
            ++RightNum;
        }
        else
        {
            ++LeftNum;
        }
    }
    RightIdx = 0;
    LeftIdx = N-1;
    while(RightIdx < LeftIdx)
    {
        while(A[RightIdx] != 1)
        {
            --LeftNum;
            if(++RightIdx == N)
            {
                break;
            }
        }
        while(A[LeftIdx] != 0)
        {
            --RightNum;
            if(--LeftIdx == -1)
            {
                break;
            }
        }
        if(RightIdx==N || LeftIdx==-1)
        {
            break;
        }
        if(LeftNum < RightNum)
        {
            Ans += LeftNum;
            ++RightIdx;
            --RightNum;
        }
        else
        {
            Ans += RightNum;
            --LeftIdx;
            --LeftNum;
        }
    }
    printf("%I64d\n", Ans);
    return 0;
}
