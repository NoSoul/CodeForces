#include <stdio.h>

typedef __int64 LL;

int A[100001];
int N, D;

int BinSearch(int i)
{
    int Left = i, Right = N, Mid;
    LL temp;
    while(Right > Left)
    {
        Mid = (Left + Right) / 2;
        temp = A[Mid] - A[i];
        if(temp > D)
        {
            Right = Mid - 1;
        }
        else if(temp == D)
        {
            return Mid;
        }
        else
        {
            Left = Mid + 1;
        }
    }
    if(A[Left] - A[i] > D)
    {
        --Left;
    }
    return Left;
}

int main()
{
    int i, j;
    LL M, Sum;
    scanf("%d %d", &N, &D);
    for(i = 1; i <= N; ++i)
    {
        scanf("%d", &A[i]);
    }
    for(Sum = 0, i = 1; i < N; ++i)
    {
        j = BinSearch(i);
        M = j - i;
        Sum += M * (M - 1) / 2;
    }
    printf("%I64d\n", Sum);
    return 0;
}
