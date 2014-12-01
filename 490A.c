#include <stdio.h>

int Len[3];

int main()
{
    int N, i, j;
    int A[3][5000];
    scanf("%d", &N);
    for(i = 1; i <= N; ++i)
    {
        scanf("%d", &j);
        --j;
        A[j][Len[j]++] = i;
    }
    int Ans = Len[0];
    if(Len[1] < Ans)
    {
        Ans = Len[1];
    }
    if(Len[2] < Ans)
    {
        Ans = Len[2];
    }
    printf("%d\n", Ans);
    for(i = 0; i < Ans; ++i)
    {
        printf("%d %d %d\n", A[0][i], A[1][i], A[2][i]);
    }
    return 0;
}
