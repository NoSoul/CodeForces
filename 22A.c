#include <stdio.h>

int main()
{
    int N, i, Ans, Min;
    int A[100];
    Ans = Min = 101;
    scanf("%d", &N);
    for(i = 0; i < N; ++i)
    {
        scanf("%d", &A[i]);
        if(A[i] < Min)
        {
            Min = A[i];
        }
    }
    for(i = 0; i < N; ++i)
    {
        if(A[i] == Min)
        {
            continue;
        }
        if(A[i] < Ans)
        {
            Ans = A[i];
        }
    }
    if(Ans == 101)
    {
        puts("NO");
    }
    else
    {
        printf("%d\n", Ans);
    }
    return 0;
}
