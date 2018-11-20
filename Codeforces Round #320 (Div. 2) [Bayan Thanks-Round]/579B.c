#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int i, j;
    int val;
} Node_t;
Node_t A[320000];
char Flag[801];
int Ans[801];

int cmp(const void *a, const void *b)
{
    return (*(Node_t *)b).val - (*(Node_t *)a).val;
}

int main()
{
    int N, i, j, k = 0;
    scanf("%d", &N);
    N <<= 1;
    for(i = 2; i <= N; ++i) {
        for(j = 1; j < i; ++j) {
            A[k].i = i;
            A[k].j = j;
            scanf("%d", &A[k++].val);
        }
    }
    qsort(A, k, sizeof(Node_t), cmp);
    for(i = 0; i < k; ++i) {
        if(!Flag[A[i].i] && !Flag[A[i].j]) {
            Flag[A[i].i] = 1;
            Flag[A[i].j] = 1;
            Ans[A[i].i] = A[i].j;
            Ans[A[i].j] = A[i].i;
        }
    }
    for(i = 1; i <= N; ++i) {
        printf("%d ", Ans[i]);
    }
    puts("");
    return 0;
}
