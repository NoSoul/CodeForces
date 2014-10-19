#include <stdio.h>

int main()
{
    int i, Sum;
    int A[5];
    Sum = 0;
    for(i=0; i<5; ++i)
    {
        scanf("%d", &A[i]);
        Sum += A[i];
    }
    if(Sum%5 == 0 && Sum)
    {
        printf("%d\n", Sum/5);
    }
    else
    {
        puts("-1");
    }
    return 0;
}
