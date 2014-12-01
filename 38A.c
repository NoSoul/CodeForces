#include <stdio.h>

#define MAX 101

int A[MAX];

int main()
{
    int N, i, a, b, j;
    scanf("%d", &N);
    for(i = 1; i < N; ++i)
    {
        scanf("%d", &A[i]);
    }
    scanf("%d %d", &a, &b);
    for(j = 0, i = a; i < b; ++i)
    {
        j += A[i];
    }
    printf("%d\n", j);
    return 0;
}
