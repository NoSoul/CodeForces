#include <stdio.h>

int main()
{
    int N,M,Left,Right,i;
    int A[100001];
    while(scanf("%d",&N)!=EOF)
    {
        if(N%4==2||N%4==3)
        {
            puts("-1");
            continue;
        }
        Left=1;
        M=Right=N;
        while(N>=4)
        {
            A[Left]=Left+1;
            A[Left+1]=Right;
            A[Right-1]=Left;
            A[Right]=Right-1;
            N-=4;
            Left+=2;
            Right-=2;
        }
        if(N==1)
        {
            A[Left]=Left;
        }
        for(i=1; i<=M; ++i)
        {
            printf("%d ",A[i]);
        }
        printf("\n");
    }
    return 0;
}
