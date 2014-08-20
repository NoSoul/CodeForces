#include <stdio.h>

int main()
{
    int A,B,N,i,Flag;
    scanf("%d %d %d",&A,&B,&N);
    for(Flag=0,i=0; i<10; ++i)
    {
        if((A*10+i)%B==0)
        {
            Flag=1;
            break;
        }
    }
    if(!Flag)
    {
        printf("-1");
    }
    else
    {
        printf("%d%d",A,i);
        for(i=1; i<N; ++i)
        {
            printf("0");
        }
    }
    return 0;
}
