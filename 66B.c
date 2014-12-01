#include <stdio.h>

int N;
int A[1000];

int Left(int i)
{
    int j, k = 0;
    for(j = i - 1; j >= 0 && A[j] <= A[j + 1]; --j, ++k);
    return k;
}

int Right(int i)
{
    int j, k = 0;
    for(j = i + 1; j < N && A[j] <= A[j - 1]; ++j, ++k);
    return k;
}

int main()
{
    int i, Max, j;
    scanf("%d", &N);
    for(i = 0; i < N; ++i)
    {
        scanf("%d", &A[i]);
    }
    for(Max = i = 0; i < N; ++i)
    {
        j = Left(i) + Right(i) + 1;
        if(Max < j)
        {
            Max = j;
        }
    }
    printf("%d\n", Max);
    return 0;
}
