#include <stdio.h>

int main()
{
    int n, m, c, b;
    int A[100001], SumB[100001] = {0};
    scanf("%d %d %d", &n, &m, &c);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &A[i]);
    }
    for(int i = 1; i <= m; ++i) {
        scanf("%d", &b);
        SumB[i] = (SumB[i - 1] + b) % c;
    }
    for(int i = 1; i <= n; ++i) {
        printf("%d ", (A[i] + SumB[i < m ? i : m] - SumB[(i > n - m + 1) ? (i - n + m - 1) : 0] + c) % c);
    }
    return 0;
}
