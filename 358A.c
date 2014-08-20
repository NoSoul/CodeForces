#include <stdio.h>

typedef struct
{
    int mBegin;
    int mEnd;
} Segment_t;

Segment_t Init(int a,int b)
{
    Segment_t result;
    result.mBegin=a<b?a:b;
    result.mEnd=a>b?a:b;
    return result;
}

int Judge(Segment_t x,Segment_t y)
{
    if(y.mBegin>x.mBegin&&y.mBegin<x.mEnd&&y.mEnd>x.mEnd)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int N,i,j;
    int A[1000];
    Segment_t X,Y;
    scanf("%d",&N);
    for(i=0; i<N; ++i)
    {
        scanf("%d",&A[i]);
    }
    for(i=0; i<N-2; ++i)
    {
        for(j=i+1; j<N-1; ++j)
        {
            X=Init(A[i],A[i+1]);
            Y=Init(A[j],A[j+1]);
            if(Judge(X,Y)||Judge(Y,X))
            {
                puts("yes");
                return 0;
            }
        }
    }
    puts("no");
    return 0;
}
