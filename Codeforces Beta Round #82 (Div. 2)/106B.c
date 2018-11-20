#include <stdio.h>

typedef struct {
    int speed, ram, hdd, cost, flag;
} Laptop;
Laptop L[101];
int N;

void Solve()
{
    int i, j, Min, Minid;
    for(i = 1; i <= N; ++i) {
        for(j = 1; j <= N; ++j) {
            if(i != j) {
                if(L[i].speed < L[j].speed && L[i].ram < L[j].ram && L[i].hdd < L[j].hdd) {
                    L[i].flag = 0;
                    break;
                }
            }
        }
    }
    Min = 1001;
    for(i = 1; i <= N; ++i) {
        if(L[i].flag && L[i].cost < Min) {
            Min = L[i].cost;
            Minid = i;
        }
    }
    printf("%d\n", Minid);
    return;
}

int main()
{
    int i;
    scanf("%d", &N);
    for(i = 1; i <= N; ++i) {
        scanf("%d %d %d %d", &L[i].speed, &L[i].ram, &L[i].hdd, &L[i].cost);
        L[i].flag = 1;
    }
    Solve();
    return 0;
}
