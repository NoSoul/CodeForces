#include <stdio.h>

int main()
{
    int i,N,Sum;
    scanf("%d",&N);
    for(Sum=N,i=0; i<N; ++i)
    {
        Sum+=(N-i)*i;
    }
    printf("%d\n",Sum);
    return 0;
}

