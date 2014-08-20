#include <stdio.h>

#define MAXN 1501

char Flag[MAXN];
int Prime[240];
int Cnt=0;

void MakePrime()
{
    int i,j;
    for(i=2; i<MAXN; ++i)
    {
        if(!Flag[i])
        {
            Prime[Cnt++]=i;
            for(j=(i<<1); j<MAXN; j+=i)
            {
                Flag[j]=1;
            }
        }
    }
}

int Judge(int n)
{
    int i,j=0;
    for(i=0; Prime[i]<=n&&i<Cnt; ++i)
    {
        if(n%Prime[i]==0)
        {
            ++j;
        }
    }
    return j==2?1:0;
}

int main()
{
    int N,i,Cnt=0;
    MakePrime();
    scanf("%d",&N);
    for(i=6; i<=N; ++i)
    {
        if(Judge(i))
        {
            ++Cnt;
        }
    }
    printf("%d\n",Cnt);
    return 0;
}
