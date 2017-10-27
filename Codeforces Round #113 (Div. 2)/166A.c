#include <stdio.h>

#define MAX 50

typedef struct {
    int p, t;
} Teams;
Teams T[MAX];

int cmp(const void *a, const void *b)
{
    if((*(Teams *)a).p == (*(Teams *)b).p) {
        return (*(Teams *)a).t - (*(Teams *)b).t;
    }
    return (*(Teams *)b).p - (*(Teams *)a).p;
}

int main()
{
    int N, K, i, j;
    scanf("%d %d", &N, &K);
    for(i = 0; i < N; ++i) {
        scanf("%d %d", &T[i].p, &T[i].t);
    }
    qsort(T, N, sizeof(Teams), cmp);
    for(i = 0; i < N; ++i) {
        if(T[i].p == T[K - 1].p && T[i].t == T[K - 1].t) {
            break;
        }
    }
    for(j = 0; i < N; ++i, ++j) {
        if(!(T[i].p == T[K - 1].p && T[i].t == T[K - 1].t)) {
            break;
        }
    }
    printf("%d\n", j);
    return 0;
}
