#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} Round_t;
Round_t R[4001];

int cmp(const void *a, const void *b)
{
    return (*(Round_t *)a).y - (*(Round_t *)b).y;
}

int main()
{
    int X, K, i, Div, Min, Max;
    scanf("%d %d", &X, &K);
    R[K].x = R[K].y = X;
    R[K + 1].x = R[K + 1].y = 0;
    for(i = 0; i < K; ++i) {
        scanf("%d", &Div);
        if(Div == 1) {
            scanf("%d %d", &R[i].x, &R[i].y);
        } else {
            scanf("%d", &R[i].x);
            R[i].y = R[i].x;
        }
    }
    qsort(R, K + 2, sizeof(Round_t), cmp);
    Min = Max = 0;
    for(i = 1; i < K + 2; ++i) {
        int now = R[i].x - R[i - 1].y - 1;
        Max += now;
        Min += now / 2 + (now & 1);
    }
    printf("%d %d\n", Min, Max);
    return 0;
}
