#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int d;
    int v;
} Dig_t;
Dig_t D[10];

int cmp(const void *a, const void *b)
{
    if((*(Dig_t *)a).v == (*(Dig_t *)b).v) {
        return (*(Dig_t *)b).d - (*(Dig_t *)a).d;
    }
    return (*(Dig_t *)a).v - (*(Dig_t *)b).v;
}

int main()
{
    int V, i, j, mod, maxd, maxv, cnt;
    scanf("%d", &V);
    for(i = 1; i < 10; ++i) {
        D[i].d = i;
        scanf("%d", &D[i].v);
    }
    qsort(D + 1, 9, sizeof(Dig_t), cmp);
    if(V < D[1].v) {
        printf("-1\n");
    } else if(V % D[1].v == 0) {
        for(i = 0; i < V / D[1].v; ++i) {
            printf("%d", D[1].d);
        }
        printf("\n");
    } else {
        mod = V % D[1].v;
        cnt = V / D[1].v;
        maxd = 0;
        while(1) {
            for(j = 2; j < 10; ++j) {
                if(D[j].v / D[1].v >= 2) {
                    continue;
                }
                if(D[j].v <= D[1].v + mod) {
                    if(D[j].d > maxd) {
                        maxv = D[j].v;
                        maxd = D[j].d;
                    }
                }
            }
            if(maxd == 0 || maxd < D[1].d) {
                break;
            } else {
                printf("%d", maxd);
                mod -= maxv - D[1].v;
                --cnt;
                if(cnt == 0) {
                    break;
                }
                maxd = 0;
            }
        }
        for(i = 0; i < cnt; ++i) {
            printf("%d", D[1].d);
        }
        printf("\n");
    }
    return 0;
}
