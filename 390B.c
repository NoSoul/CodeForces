#include <stdio.h>

int A[100000];
int B[100000];

int main()
{
    int N, i;
    long long Sum;
    scanf("%d", &N);
    for(i = 0; i < N; ++i)
    {
        scanf("%d", &A[i]);
    }
    for(i = 0; i < N; ++i)
    {
        scanf("%d", &B[i]);
    }
    Sum = 0;
    for(i = 0; i < N; ++i)
    {
        if((A[i] + A[i]) < B[i] || B[i] == 1)
        {
            --Sum;
        }
        else
        {
            long long temp = B[i] / 2;
            Sum += temp * ((long long)B[i] - temp);
        }
    }
    printf("%I64d\n", Sum);
    return 0;
}
