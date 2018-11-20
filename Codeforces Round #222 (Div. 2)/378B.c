#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN    100000

typedef struct {
    int id;
    int value;
    char first;
} Res_t;
Res_t Data[MAXN << 1];
char Hash1[MAXN], Hash2[MAXN];

int cmp(const void *a, const void *b)
{
    return (*(Res_t *)a).value - (*(Res_t *)b).value;
}

int main()
{
    int N, i;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d %d", &Data[i * 2].value, &Data[i * 2 + 1].value);
        Data[i * 2].id = i;
        Data[i * 2].first = 1;
        Data[i * 2 + 1].id = i;
        Data[i * 2 + 1].first = 0;
    }
    qsort(Data, 2 * N, sizeof(Res_t), cmp);
    for(i = 0; i < N / 2; ++i) {
        Hash1[i] = Hash2[i] = 1;
    }
    for(i = 0; i < N; ++i) {
        if(Data[i].first) {
            Hash1[Data[i].id] = 1;
        } else {
            Hash2[Data[i].id] = 1;
        }
    }
    for(i = 0; i < N; ++i) {
        printf("%d", Hash1[i]);
    }
    printf("\n");
    for(i = 0; i < N; ++i) {
        printf("%d", Hash2[i]);
    }
    return 0;
}
