#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a, b;
} Node_t;

int cmp(const void *a, const void *b)
{
    return (*(Node_t *)a).b - (*(Node_t *)b).b;
}

Node_t A[100000];

int main()
{
    int N, R, AVG, i;
    long long Ans, Sum, Bound;
    Ans = 0;
    Sum = 0;
    scanf("%d %d %d", &N, &R, &AVG);
    Bound = AVG;
    Bound *= N;
    for(i = 0; i < N; ++i) {
        scanf("%d %d", &A[i].a, &A[i].b);
        Sum += A[i].a;
    }
    if(Sum >= Bound) {
        puts("0");
        return 0;
    }
    qsort(A, N, sizeof(Node_t), cmp);
    for(i = 0; i < N; ++i) {
        long long available = (long long)R - A[i].a;
        long long need = Bound - Sum;
        if(need > available) {
            Ans += available * A[i].b;
            Sum += available;
        } else {
            Ans += need * A[i].b;
            Sum += need;
            break;
        }
    }
    printf("%I64d\n", Ans);
    return 0;
}
