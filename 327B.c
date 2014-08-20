#include <stdio.h>

#define MAXN	1300000

char Flag[MAXN];
int Prime[100000];
int Size;

void Make()
{
    int i,j;
    for(i=2; i<MAXN; ++i)
    {
        if(!Flag[i])
        {
            Prime[Size++]=i;
            if(Size==100000)
            {
                return;
            }
            for(j=i+i; j<MAXN; j+=i)
            {
                Flag[j]=1;
            }
        }
    }
}

int main()
{
    int N,i;
    scanf("%d",&N);
    Make();
    for(i=0; i<N; ++i)
    {
        printf("%d ",Prime[i]);
    }
    return 0;
}
