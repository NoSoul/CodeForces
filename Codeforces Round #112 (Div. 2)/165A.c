#include <stdio.h>

typedef struct {
    int x, y;
} Point;
Point P[200];

int main()
{
    int N, i, j, cnt;
    char flag[4];
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d %d", &P[i].x, &P[i].y);
    }
    for(cnt = i = 0; i < N; ++i) {
        flag[0] = flag[1] = flag[2] = flag[3] = 0;
        for(j = 0; j < N; ++j) {
            if(j == i) {
                continue;
            }
            if(P[j].x > P[i].x && P[j].y == P[i].y) {
                flag[0] = 1;
            }
            if(P[j].x < P[i].x && P[j].y == P[i].y) {
                flag[1] = 1;
            }
            if(P[j].x == P[i].x && P[j].y < P[i].y) {
                flag[2] = 1;
            }
            if(P[j].x == P[i].x && P[j].y > P[i].y) {
                flag[3] = 1;
            }
        }
        if(flag[0] == 1 && flag[1] == 1 && flag[2] == 1 && flag[3] == 1) {
            ++cnt;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
