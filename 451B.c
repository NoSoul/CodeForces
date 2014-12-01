#include <stdio.h>

int A[100002];

int Judge(int idx, int len)
{
    int i;
    for(i = idx; i < len; ++i)
    {
        if(A[i] > A[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int N, i, start, end;
    A[0] = 0;
    scanf("%d", &N);
    for(i = 1; i <= N; ++i)
    {
        scanf("%d", &A[i]);
    }
    A[N + 1] = 1000000001;
    start = N + 1;
    for(i = 1; i <= N; ++i)
    {
        if(A[i] > A[i + 1])
        {
            start = i;
            break;
        }
    }
    if(start == N + 1)
    {
        printf("yes\n1 1\n");
        return 0;
    }
    end = N;
    for(i = start; i <= N; ++i)
    {
        if(A[i] < A[i + 1])
        {
            end = i;
            break;
        }
    }
    if(A[end] > A[start - 1] && A[start] < A[end + 1] && Judge(end + 1, N + 1))
    {
        printf("yes\n%d %d\n", start, end);
    }
    else
    {
        printf("no\n");
    }
    return 0;
}
