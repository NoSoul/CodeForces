#include <stdio.h>

int main()
{
    int N,i,Num;
    int A[8]= {0};
    scanf("%d",&N);
    for(i=0; i<N; ++i)
    {
        scanf("%d",&Num);
        if(Num==5||Num==7)
        {
            printf("-1\n");
            return 0;
        }
        ++A[Num];
    }
    if(A[4]<=A[1]&&A[4]<=A[2])
    {
        A[1]-=A[4];
        A[2]-=A[4];
        if(A[6]==A[1]&&(A[2]+A[3]==A[6]))
        {
            for(i=0; i<A[4]; ++i)
            {
                printf("1 2 4\n");
            }
            for(i=0; i<A[2]; ++i)
            {
                printf("1 2 6\n");
            }
            for(i=0; i<A[3]; ++i)
            {
                printf("1 3 6\n");
            }
        }
        else
        {
            printf("-1\n");
        }
    }
    else
    {
        printf("-1\n");
    }
    return 0;
}
