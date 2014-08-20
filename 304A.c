#include <stdio.h>

int main()
{
    int N,a,b,c,Cnt=0;
    scanf("%d",&N);
    for(a=3; a<N-1; ++a)
    {
        for(b=a+1; b<N; ++b)
        {
            c=sqrt(a*a+b*b);
            if(c>N)
            {
                break;
            }
            if(c*c==a*a+b*b)
            {
                ++Cnt;
            }
        }
    }
    printf("%d\n",Cnt);
    return 0;
}
