#include <stdio.h>
#include <stdlib.h>

int N;
int A[100001];
char Hash[5001];

int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}

int BinMaxSearch(int key)
{
    int Left=1,Right=N,Mid;
    while(Right>Left)
    {
        Mid=(Left+Right)/2;
        if(A[Mid]<=key)
        {
            Left=Mid+1;
        }
        else
        {
            Right=Mid-1;
        }
    }
    if(A[Left]!=key)
    {
        --Left;
    }
    return Left;
}

int BinMinSearch(int key)
{
    int Left=1,Right=N,Mid;
    while(Right>Left)
    {
        Mid=(Left+Right)/2;
        if(A[Mid]+A[Mid]>=key)
        {
            Right=Mid-1;
        }
        else
        {
            Left=Mid+1;
        }
    }
    if(A[Left]+A[Left]>=key)
    {
        --Left;
    }
    return Left;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int i,j,Min;
    scanf("%d",&N);
    for(i=1; i<=N; ++i)
    {
        scanf("%d",&A[i]);
        Hash[A[i]]=1;
    }
    qsort(A+1,N,sizeof(int),cmp);
    for(Min=0x7fffffff,i=1; i<5001; ++i)
    {
        if(Hash[i])
        {
            j=N-BinMaxSearch(i)+BinMinSearch(i);
            if(j<Min)
            {
                Min=j;
            }
        }
    }
    printf("%d\n",Min);
    return 0;
}
