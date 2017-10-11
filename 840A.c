#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int val;
} Node_t;
Node_t A[200001];
Node_t B[200001];
Node_t C[200001];

int cmpA(const void *a, const void *b)
{
    return ((Node_t *)a)->val - ((Node_t *)b)->val;
}

int cmpB(const void *a, const void *b)
{
    return ((Node_t *)a)->id - ((Node_t *)b)->id;
}

int main()
{
    int m;
    scanf("%d", &m);
    for(int i = 0; i < m; ++i) {
        A[i].id = i;
        scanf("%d", &A[i].val);
    }
    for(int i = 0; i < m; ++i) {
        B[i].id = i;
        scanf("%d", &B[i].val);
    }
    qsort(A, m, sizeof(Node_t), cmpA);
    qsort(B, m, sizeof(Node_t), cmpA);
    for(int i = 0; i < m; ++i) {
        C[i].id = B[i].id;
        C[i].val = A[m - i - 1].val;
    }
    qsort(C, m, sizeof(Node_t), cmpB);
    for(int i = 0; i < m; ++i) {
        printf("%d ", C[i].val);
    }
    puts("");
    return 0;
}
