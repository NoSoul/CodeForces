#include <stdio.h>
#include <stdlib.h>

#define MAXN    100000
#define MIN(a, b) ((a)<(b)?(a):(b))
#define MAX(a, b) ((a)>(b)?(a):(b))

typedef struct {
    int id;
    int x;
} Node_t;
Node_t A[MAXN];
int Ans[MAXN][2];

int cmp(const void *a, const void *b)
{
    return (*(Node_t *)a).x - (*(Node_t *)b).x;
}

int main()
{
    int N, i;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        A[i].id = i;
        scanf("%d", &A[i].x);
    }
    qsort(A, N, sizeof(Node_t), cmp);
    for(i = 0; i < N; ++i) {
        if(i == 0) {
            Ans[A[i].id][0] = abs(A[i].x - A[i + 1].x);
        } else if(i == N - 1) {
            Ans[A[i].id][0] = abs(A[i].x - A[i - 1].x);
        } else {
            Ans[A[i].id][0] = MIN(abs(A[i].x - A[i - 1].x), abs(A[i].x - A[i + 1].x));
        }
        Ans[A[i].id][1] = MAX(abs(A[i].x - A[0].x), abs(A[i].x - A[N - 1].x));
    }
    for(i = 0; i < N; ++i) {
        printf("%d %d\n", Ans[i][0], Ans[i][1]);
    }
    return 0;
}
