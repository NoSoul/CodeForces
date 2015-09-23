#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int m;
    int s;
} Node_t;
Node_t A[100001];
long long Sum[100001];

int cmp(const void *a, const void *b)
{
    return (*(Node_t *)a).m - (*(Node_t *)b).m;
}

int main()
{
    int N, d, i, j;
    long long Ans = 0;
    scanf("%d %d", &N, &d);
    for(i = 1; i <= N; ++i) {
        scanf("%d %d", &A[i].m, &A[i].s);
    }
    qsort(A + 1, N, sizeof(Node_t), cmp);
    Sum[0] = 0;
    for(i = 1; i <= N; ++i) {
        Sum[i] = Sum[i - 1] + A[i].s;
    }
    j = 1;
    for(i = 1; i <= N; ++i) {
        while(j <= N && A[j].m - A[i].m < d) {
            ++j;
        }
        if(Sum[j - 1] - Sum[i - 1] > Ans) {
            Ans = Sum[j - 1] - Sum[i - 1];
        }
    }
    printf("%I64d\n", Ans);
    return 0;
}
