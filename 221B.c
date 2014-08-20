#include <stdio.h>
#include <math.h>

int A[10];

void Init(int a)
{
    while(a)
    {
        ++A[a%10];
        a/=10;
    }
    return;
}

int Judge(int b)
{
    while(b)
    {
        if(A[b%10])
        {
            return 1;
        }
        b/=10;
    }
    return 0;
}

int main()
{
    int X,i,Cnt;
    scanf("%d",&X);
    Init(X);
    for(i=1,Cnt=0; i<=sqrt(X); ++i)
    {
        if(X%i==0)
        {
            if(Judge(i))
            {
                ++Cnt;
            }
            if(X/i!=i)
            {
                if(Judge(X/i))
                {
                    ++Cnt;
                }
            }
        }
    }
    printf("%d\n",Cnt);
    return 0;
}
