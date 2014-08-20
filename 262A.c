#include <stdio.h>

int Judge(int n)
{
    int cnt=0;
    while(n)
    {
        cnt+=n%10==4||n%10==7;
        n/=10;
    }
    return cnt;
}

int main()
{
    int N,K,Cnt,num;
    scanf("%d %d",&N,&K);
    Cnt=0;
    while(N--)
    {
        scanf("%d",&num);
        if(Judge(num)<=K)
        {
            ++Cnt;
        }
    }
    printf("%d\n",Cnt);
    return 0;
}

