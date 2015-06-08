#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id, value;
} Player_t;
Player_t A[300000];

int cmp1(const void *a, const void *b)
{
    return (*(Player_t *)a).value - (*(Player_t *)b).value;
}

int cmp2(const void *a, const void *b)
{
    return (*(Player_t *)a).id - (*(Player_t *)b).id;
}

int main()
{
    int N, i;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d", &A[i].value);
        A[i].id = i;
    }
    qsort(A, N, sizeof(Player_t), cmp1);
    for(i = 1; i < N; ++i) {
        if(A[i].value <= A[i - 1].value) {
            A[i].value = A[i - 1].value + 1;
        }
    }
    qsort(A, N, sizeof(Player_t), cmp2);
    for(i = 0; i < N; ++i) {
        printf("%d ", A[i].value);
    }
    return 0;
}
