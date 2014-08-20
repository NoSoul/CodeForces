#include <stdio.h>

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int N,i,Left,Right,Cnt,suml,sumr,Min,p;
    int A[100001];
    while(scanf("%d",&N)!=EOF)
    {
        for(Left=Right=Cnt=i=0; i<N; ++i)
        {
            scanf("%d",&A[i]);
            if(A[i]==0)
            {
                ++Cnt;
            }
            else if(A[i]<0)
            {
                ++Left;
            }
            else
            {
                ++Right;
            }
        }
        Min=0x7fffffff;
        for(suml=sumr=i=0; i<N-1; ++i)
        {
            if(A[i]<0)
            {
                ++suml;
            }
            else if(A[i]>0)
            {
                ++sumr;
            }
            if(sumr+Left-suml<Min)
            {
                Min=sumr+Left-suml;
            }
            p=0;
            if(A[0]<0)
            {
                p=-1;
            }
            else if(A[0]>0)
            {
                p=1;
            }
            if(suml+Left-suml+p<Min)
            {
                Min=suml+Left-suml+p;
            }
            p=0;
            if(A[N-1]>0)
            {
                p=-1;
            }
            else if(A[N-1]<0)
            {
                p=1;
            }
            if(sumr+Right-sumr+p<Min)
            {
                Min=sumr+Right-sumr+p;
            }
        }
        printf("%d\n",Cnt+Min);
    }
    return 0;
}
