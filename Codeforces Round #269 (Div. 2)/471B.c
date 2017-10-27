#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int h;
} Task_t;
Task_t TData[2000];
int Hash[2001];

int cmp(const void *a, const void *b)
{
    if((*(Task_t *)a).h == (*(Task_t *)b).h) {
        return (*(Task_t *)a).id - (*(Task_t *)b).id;
    }
    return (*(Task_t *)a).h - (*(Task_t *)b).h;
}

int main()
{
    int N, i, j, Cnt = 0;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d", &TData[i].h);
        TData[i].id = i + 1;
        ++Hash[TData[i].h];
        if(Hash[TData[i].h] >= 2) {
            ++Cnt;
        }
    }
    if(Cnt < 2) {
        puts("NO");
        return 0;
    }
    puts("YES");
    qsort(TData, N, sizeof(Task_t), cmp);
    for(j = 0; j < N; ++j) {
        printf("%d ", TData[j].id);
    }
    puts("");
    int target = 2;
    int Pre = 0;
    for(i = 0; i < N; ++i) {
        if(TData[i].h != Pre) {
            Pre = TData[i].h;
            if(Hash[TData[i].h] == 2) {
                for(j = 0; j < i; ++j) {
                    printf("%d ", TData[j].id);
                }
                printf("%d %d ", TData[i + 1].id, TData[i].id);
                for(j = i + 2; j < N; ++j) {
                    printf("%d ", TData[j].id);
                }
                puts("");
                if(--target == 0) {
                    return 0;
                }
            } else if(Hash[TData[i].h] > 2) {
                for(j = 0; j < i; ++j) {
                    printf("%d ", TData[j].id);
                }
                printf("%d %d %d ", TData[i].id, TData[i + 2].id, TData[i + 1].id);
                for(j = i + 3; j < N; ++j) {
                    printf("%d ", TData[j].id);
                }
                puts("");
                if(--target == 0) {
                    return 0;
                }
                for(j = 0; j < i; ++j) {
                    printf("%d ", TData[j].id);
                }
                printf("%d %d %d ", TData[i + 1].id, TData[i].id, TData[i + 2].id);
                for(j = i + 3; j < N; ++j) {
                    printf("%d ", TData[j].id);
                }
                puts("");
                if(--target == 0) {
                    return 0;
                }

            }
        }
    }
    return 0;
}
