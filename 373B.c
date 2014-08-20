#include <stdio.h>
#include <string.h>

typedef long long LL_t;

LL_t GetSn(LL_t num)
{
    LL_t res=0;
    while(num)
    {
        num/=10;
        ++res;
    }
    return res;
}

int main()
{
    LL_t w,m,k,Sn,Max,Ans=0,i;
    scanf("%lld %lld %lld",&w,&m,&k);
    while(w)
    {
        Sn=GetSn(m);
        Max=1;
        for(i=0; i<Sn; ++i)
        {
            Max*=10;
        }
        if(w/(k*Sn)<=(Max-m))
        {
            Ans+=w/(k*Sn);
            w=0;
        }
        else
        {
            Ans+=Max-m;
            w-=(Max-m)*Sn*k;
        }
        m=Max;
    }
    printf("%lld\n",Ans);
    return 0;
}
