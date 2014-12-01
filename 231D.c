#include <stdio.h>

int main()
{
    int X, Y, Z, X0, Y0, Z0, i, Sum;
    int A[6];
    scanf("%d %d %d %d %d %d", &X, &Y, &Z, &X0, &Y0, &Z0);
    for(Sum = i = 0; i < 6; ++i)
    {
        scanf("%d", &A[i]);
    }
    if(Y < 0)
    {
        Sum += A[0];
    }
    if(Y > Y0)
    {
        Sum += A[1];
    }
    if(Z < 0)
    {
        Sum += A[2];
    }
    if(Z > Z0)
    {
        Sum += A[3];
    }
    if(X < 0)
    {
        Sum += A[4];
    }
    if(X > X0)
    {
        Sum += A[5];
    }
    printf("%d\n", Sum);
    return 0;
}
