#include <stdio.h>
#include <string.h>

char Digit[10];

int Fun(char *num,int k)
{
    int i;
    memset(Digit,0,sizeof(Digit));
    for(i=0; num[i]!='\0'; ++i)
    {
        Digit[num[i]-'0']=1;
    }
    for(i=0; i<=k; ++i)
    {
        if(Digit[i]==0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int N,K,i,Cnt;
    char Num[11];
    scanf("%d %d",&N,&K);
    for(Cnt=i=0; i<N; ++i)
    {
        scanf("%s",Num);
        Cnt+=Fun(Num,K);
    }
    printf("%d\n",Cnt);
    return 0;
}
