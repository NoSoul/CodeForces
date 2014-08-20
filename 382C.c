#include <stdio.h>
#include <stdlib.h>

int A[100000];
int Res[5];

int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}

int main()
{
    int N,i,j,k,max,min;
    int cnt;
    scanf("%d",&N);
    for(i=0; i<N; ++i)
    {
        scanf("%d",&A[i]);
    }
    if(N==1)
    {
        printf("-1\n");
        return 0;
    }
    qsort(A,N,sizeof(int),cmp);
    if(N==2)
    {
        if(A[0]==A[1])
        {
            printf("1\n%d\n",A[0]);
        }
        else if(A[0]==A[1]-1)
        {
            printf("2\n%d %d\n",A[0]-1,A[1]+1);
        }
        else
        {
            if((A[1]-A[0])%2==0)
            {
                printf("3\n%d %d %d\n",2*A[0]-A[1],(A[0]+A[1])/2,2*A[1]-A[0]);
            }
            else
            {
                printf("2\n%d %d\n",2*A[0]-A[1],2*A[1]-A[0]);
            }
        }
    }
    else
    {
        Res[0]=A[1]-A[0];
        k=1;
        for(i=2; i<N; ++i)
        {
            for(j=0; j<k; ++j)
            {
                if(Res[j]==A[i]-A[i-1])
                {
                    break;
                }
            }
            if(j==k)
            {
                Res[k]=A[i]-A[i-1];
                ++k;
                if(k==3)
                {
                    printf("0\n");
                    return 0;
                }
            }
        }
        if(k==1)
        {
            if(Res[0]==0)
            {
                printf("1\n%d\n",A[0]);
            }
            else
            {
                printf("2\n%d %d\n",2*A[0]-A[1],2*A[N-1]-A[N-2]);
            }
        }
        else
        {
            max=Res[0]>Res[1]?Res[0]:Res[1];
            min=Res[0]<Res[1]?Res[0]:Res[1];
            cnt=0;
            if(max%2==0&&max/2==min)
            {
                for(i=1; i<N; ++i)
                {
                    if(A[i]-A[i-1]==max)
                    {
                        ++cnt;
                    }
                }
                if(cnt!=1)
                {
                    printf("0\n");
                }
                else
                {
                    for(i=1; i<N; ++i)
                    {
                        if(A[i]-A[i-1]==max)
                        {
                            printf("1\n%d\n",(A[i-1]+A[i])/2);
                            return 0;
                        }
                    }
                }
            }
            else
            {
                printf("0\n");
            }
        }
    }
    return 0;
}
