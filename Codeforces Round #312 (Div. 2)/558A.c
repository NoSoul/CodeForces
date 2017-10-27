#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, a;
} Node_t;
Node_t A[100];

int cmp(const void *a, const void *b)
{
    return (*(Node_t *)a).x - (*(Node_t *)b).x;
}

int main()
{
    int N, i, a, b, j, Sum = 0;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d %d", &A[i].x, &A[i].a);
    }
    qsort(A, N, sizeof(Node_t), cmp);
    for(i = 0; i < N; ++i) {
        if(A[i].x > 0) {
            break;
        }
    }
    a = i;
    b = N - i;
    if(a < b) {
        b = a + 1;
    } else if(a > b) {
        a = b + 1;
    }
    for(j = i - 1; a; --j, --a) {
        Sum += A[j].a;
    }
    for(j = i; b; ++j, --b) {
        Sum += A[j].a;
    }
    printf("%d\n", Sum);
    return 0;
}
