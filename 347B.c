#include <stdio.h>

int A[100001];

int main()
{
    int N, i, Cnt = 0;
    char flag = 1;
    scanf("%d", &N);
    for(i = 0; i < N; ++i)
    {
        scanf("%d", &A[i]);
    }
    for(i = 0; i < N; ++i)
    {
        if(A[i] == i)
        {
            ++Cnt;
        }
        else if(A[A[i]] == i)
        {
            flag = 2;
        }
    }
    if(Cnt == N)
    {
        flag = 0;
    }
    printf("%d\n", Cnt + flag);
    return 0;
}
