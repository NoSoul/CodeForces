#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int k, b;
    long long y1;
    long long y2;
} Node_t;
Node_t A[100000];

int cmp(const void *a, const void *b)
{
    if(((Node_t*)a)->y1 == ((Node_t*)b)->y1) {
        return ((Node_t*)a)->y2 > ((Node_t*)b)->y2 ? 1 : -1;
    }
    return ((Node_t*)a)->y1 > ((Node_t*)b)->y1 ? 1 : -1;
}

int main()
{
    int N, x1, x2, i, k, b;
    scanf("%d %d %d", &N, &x1, &x2);
    for(i = 0; i < N; ++i) {
        scanf("%d %d", &k, &b);
        A[i].k = k;
        A[i].b = b;
        A[i].y1 = (long long)k * x1 + b;
        A[i].y2 = (long long)k * x2 + b;
    }
    qsort(A, N, sizeof(Node_t), cmp);
    for(i = 0; i < N - 1; ++i) {
        long long a = A[i + 1].b - A[i].b;
        long long b = A[i].k - A[i + 1].k;
        long long c = A[i].k - A[i + 1].k;
        b *= x1;
        c *= x2;
        if(a > b && a < c) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}
