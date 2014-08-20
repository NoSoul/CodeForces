#include <stdio.h>

int GCD(int a,int b)
{
    int temp;
    while(b)
    {
        temp=a%b;
        a=b;
        b=temp;
    }
    return a;
}

int main()
{
    int N,i,a,b;
    scanf("%d %d",&N,&a);
    for(i=1; i<N; ++i)
    {
        scanf("%d",&b);
        a=GCD(a,b);
    }
    printf("%d\n",a*N);
    return 0;
}
