#include <stdio.h>

int main()
{
    int A[100];
    int N, i, j, Ans, Cur;
    scanf("%d", &N);
    for(i = 0; i < N; ++i)
    {
        scanf("%d", &A[i]);
    }
    Ans = 10000;
    for(i = 1; i < N - 1; ++i)
    {
        Cur = A[i + 1] - A[i - 1];
        for(j = 1; j < i; ++j)
        {
            if(A[j] - A[j - 1] > Cur)
            {
                Cur = A[j] - A[j - 1];
            }
        }
        for(j = i + 2; j < N; ++j)
        {
            if(A[j] - A[j - 1] > Cur)
            {
                Cur = A[j] - A[j - 1];
            }
        }
        if(Ans > Cur)
        {
            Ans = Cur;
        }
    }
    printf("%d\n", Ans);
    return 0;
}
