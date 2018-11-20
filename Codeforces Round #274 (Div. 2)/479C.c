#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int ai, bi;
} Exam_t;
Exam_t A[5000];

int cmp(const void *a, const void *b)
{
    if((*(Exam_t *)a).ai == (*(Exam_t *)b).ai) {
        return (*(Exam_t *)a).bi - (*(Exam_t *)b).bi;
    }
    return (*(Exam_t *)a).ai - (*(Exam_t *)b).ai;
}

int main()
{
    int N, i, Ans;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d %d", &A[i].ai, &A[i].bi);
    }
    qsort(A, N, sizeof(Exam_t), cmp);
    Ans = A[0].bi;
    for(i = 1; i < N; ++i) {
        if(Ans <= A[i].bi) {
            Ans = A[i].bi;
        } else {
            Ans = A[i].ai;
        }
    }
    printf("%d\n", Ans);
    return 0;
}
