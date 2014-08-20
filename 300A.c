#include <stdio.h>

int A[100];

int main()
{
    int i,N,Cnt,other;
    scanf("%d",&N);
    for(Cnt=i=0; i<N; ++i)
    {
        scanf("%d",&A[i]);
        if(A[i]==0)
        {
            ++Cnt;
        }
    }
    for(other=i=0; i<N; ++i)
    {
        if(A[i]<0)
        {
            printf("1 %d\n",A[i]);
            A[i]=0;
            ++other;
            break;
        }
    }
    for(i=0; i<N; ++i)
    {
        if(A[i]>0)
        {
            printf("1 %d\n",A[i]);
            A[i]=0;
            ++other;
            break;
        }
    }
    if(i==N)
    {
        printf("2");
        for(i=0; i<N; ++i)
        {
            if(A[i]<0)
            {
                printf(" %d",A[i]);
                A[i]=0;
                ++other;
                if(other==3)
                {
                    printf("\n");
                    break;
                }
            }
        }
    }
    printf("%d",N-other);
    for(i=0; i<Cnt; ++i)
    {
        printf(" 0");
    }
    for(i=0; i<N; ++i)
    {
        if(A[i]!=0)
        {
            printf(" %d",A[i]);
        }
    }
    printf("\n");
    return 0;
}
