#include <stdio.h>

#define eps 1e-8

int main()
{
    int N,X,Y;
    double A;
    scanf("%d %d %d",&N,&X,&Y);
    A=1.0*N*Y/100;
    N=(int)A;
    if(A-1.0*N>eps)
    {
        ++N;
    }
    if(N>X)
    {
        printf("%d\n",N-X);
        return 0;
    }
    puts("0");
    return 0;
}
