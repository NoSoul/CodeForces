#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int Cnt;
    int Num;
} Node_t;
Node_t Data[2000000];
int *A;

int cmp(const void *a,const void *b)
{
    return (*(Node_t *)a).Num-(*(Node_t *)b).Num;
}

int main()
{
    int N,Size,i,j,k,Sum;
    scanf("%d",&N);
    A=(int *)malloc(sizeof(int)*N);
    for(i=0; i<N; ++i)
    {
        scanf("%d",&A[i]);
    }
    Data[0].Num=A[0];
    Data[0].Cnt=1;
    Size=1;
    for(i=1; i<N; ++i)
    {
        if(A[i]==Data[Size-1].Num)
        {
            ++Data[Size-1].Cnt;
        }
        else
        {
            Data[Size].Num=A[i];
            Data[Size].Cnt=1;
            ++Size;
        }
    }
    free(A);
    for(i=0; i<Size; ++i)
    {
        for(j=17; Data[i].Cnt>1&&j>0; --j)
        {
            if(Data[i].Cnt>=(1<<j))
            {
                Data[i].Cnt-=(1<<j);
                for(k=i+1; k<Size; ++k)
                {
                    if(Data[k].Num==(j+Data[i].Num))
                    {
                        ++Data[k].Cnt;
                        break;
                    }
                }
                if(k==Size)
                {
                    Data[Size].Num=j+Data[i].Num;
                    Data[Size].Cnt=1;
                    ++Size;
                    qsort(Data+i+1,Size-i-1,sizeof(Node_t),cmp);
                }
            }
        }
    }
    for(i=j=0; i<Size; ++i)
    {
        if(Data[i].Cnt==1)
        {
            Data[j]=Data[i];
            ++j;
        }
    }
    Size=j;
    for(Sum=Data[0].Num,i=1; i<Size; ++i)
    {
        Sum+=Data[i].Num-Data[i-1].Num-1;
    }
    printf("%d\n",Sum);
    return 0;
}
