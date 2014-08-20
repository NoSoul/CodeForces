#include <stdio.h>

int main()
{
    int A[3], B[3];
    int N, SumA, SumB, MinA, MinB;
    scanf("%d %d %d", &A[0], &A[1], &A[2]);
    scanf("%d %d %d", &B[0], &B[1], &B[2]);
    scanf("%d", &N);
    SumA = A[0] + A[1] + A[2];
    SumB = B[0] + B[1] + B[2];
    MinA = SumA/5 + ((SumA%5)?1:0);
    MinB = SumB/10 + ((SumB%10)?1:0);
    if(N>=MinA+MinB)
    {
        puts("YES");
    }
    else
    {
        puts("NO");
    }
    return 0;
}
