#include <stdio.h>

int main()
{
    int N, K, Mod, i, j;
    int A[100];
    scanf("%d %d", &N, &K);
    Mod = K % N;
    for(i = 0; i < N; ++i)
    {
        A[i] = K / N;
        if(Mod)
        {
            ++A[i];
            --Mod;
        }
    }
    for(i = 0; i < N; ++i)
    {
        for(j = i; j < N; ++j)
        {
            printf("%d ", A[j]);
        }
        for(j = 0; j < i; ++j)
        {
            printf("%d ", A[j]);
        }
        printf("\n");
    }
    return 0;
}
