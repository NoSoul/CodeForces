#include <stdio.h>

int A[100];

int main()
{
    int N,i,Min,Cnt,index;
    scanf("%d",&N);
    for(Min=0x7fffffff,i=1; i<=N; ++i)
    {
        scanf("%d",&A[i]);
        if(A[i]<Min)
        {
            Min=A[i];
        }
    }
    for(Cnt=0,i=1; i<=N; ++i)
    {
        if(A[i]==Min)
        {
            ++Cnt;
            index=i;
        }
    }
    if(Cnt>1)
    {
        puts("Still Rozdil");
    }
    else
    {
        printf("%d\n",index);
    }
    return 0;
}
