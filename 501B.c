#include <stdio.h>
#include <string.h>

typedef struct {
    char old[21];
    char new[21];
    int next;
} Request_t;
Request_t Q[1000];

int main()
{
    int N, i, j;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%s %s", Q[i].old, Q[i].new);
        Q[i].next = -1;
    }
    for(i = 0; i < N - 1; ++i) {
        for(j = 0; j < N; ++j) {
            if(strcmp(Q[i].new, Q[j].old) == 0) {
                memcpy(Q[j].old, Q[i].old, strlen(Q[i].old));
                Q[j].old[strlen(Q[i].old)] = '\0';
                Q[i].next = j;
                break;
            }
        }
    }
    int Ans = 0;
    for(i = 0; i < N; ++i) {
        Ans += Q[i].next == -1;
    }
    printf("%d\n", Ans);
    for(i = 0; i < N; ++i) {
        if(Q[i].next == -1) {
            printf("%s %s\n", Q[i].old, Q[i].new);
        }
    }
    return 0;
}
