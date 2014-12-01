#include <stdio.h>

int Hash[101];
int A[101];
int Ans[101];

int main()
{
    int N, M, i;
    scanf("%d %d", &N, &M);
    for(i = 0; i < N; ++i)
    {
        scanf("%d", &A[i]);
        Hash[A[i]] = 1;
    }
    while(M--)
    {
        scanf("%*d %*d");
    }
    int temp = 0;
    for(i = 0; i < 101; ++i)
    {
        if(Hash[i])
        {
            Ans[i] = temp;
            temp ^= 1;
        }
    }
    for(i = 0; i < N; ++i)
    {
        printf("%d ", Ans[A[i]]);
    }
    return 0;
}
