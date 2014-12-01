#include <stdio.h>

#define MAX 100000

int A[MAX], B[MAX];
int Edge[MAX][2];

int main()
{
    int N, M, x, y, i, j, Cnt;
    scanf("%d %d %d %d", &N, &M, &x, &y);
    for(i = 0; i < N; ++i)
    {
        scanf("%d", &A[i]);
    }
    for(i = 0; i < M; ++i)
    {
        scanf("%d", &B[i]);
    }
    Cnt = i = j = 0;
    while(i < N && j < M)
    {
        if(B[j] < A[i] - x)
        {
            ++j;
        }
        else if(B[j] > A[i] + y)
        {
            ++i;
        }
        else
        {
            Edge[Cnt][0] = i + 1;
            Edge[Cnt++][1] = j + 1;
            ++i;
            ++j;
        }
    }
    printf("%d\n", Cnt);
    for(i = 0; i < Cnt; ++i)
    {
        printf("%d %d\n", Edge[i][0], Edge[i][1]);
    }
    return 0;
}
