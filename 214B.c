#include <stdio.h>
#include <stdlib.h>

#define MAXN 100010

int Data[MAXN];
int N;

void Dec(int key)
{
    int i;
    for(i=N-1; i>=0; --i)
    {
        if(Data[i]%3==key)
        {
            Data[i]=-1;
            return;
        }
    }
}

int cmp(const void *a,const void *b)
{
    return *(int *)b-*(int *)a;
}

int main()
{
    int Zero,One,Two,i,Sum,F;
    while(scanf("%d",&N)!=EOF)
    {
        Sum=Zero=One=Two=0;
        for(i=0; i<N; ++i)
        {
            scanf("%d",&Data[i]);
            if(Data[i]==0)
            {
                ++Zero;
            }
            if(Data[i]%3==1)
            {
                ++One;
            }
            if(Data[i]%3==2)
            {
                ++Two;
            }
            Sum+=Data[i];
        }
        if(Zero==0)
        {
            puts("-1");
            continue;
        }
        qsort(Data,N,sizeof(int),cmp);
        if(Sum%3==0)
        {
            if(Zero==N)
            {
                puts("0");
                continue;
            }
            else
            {
                for(i=0; i<N; ++i)
                {
                    printf("%d",Data[i]);
                }
                puts("");
            }
        }
        else
        {
            if(Sum%3==1)
            {
                if(One==0&&Two<2)
                {
                    puts("-1");
                    continue;
                }
                if(One>0)
                {
                    Dec(1);
                }
                else
                {
                    Dec(2);
                    Dec(2);
                }
            }
            else
            {
                if(Two==0&&One<2)
                {
                    puts("-1");
                    continue;
                }
                if(Two>0)
                {
                    Dec(2);
                }
                else
                {
                    Dec(1);
                    Dec(1);
                }
            }
            for(F=i=0; Data[i]!=0; ++i)
            {
                if(Data[i]!=-1)
                {
                    printf("%d",Data[i]);
                    F=1;
                }
            }
            if(!F)
            {
                puts("0");
                continue;
            }
            else
            {
                for(i=0; i<Zero; ++i)
                {
                    printf("0");
                }
                puts("");
            }
        }
    }
    return 0;
}
