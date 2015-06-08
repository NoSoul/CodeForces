#include <stdio.h>

int main()
{
    int N, M, i, Min, Min4, Min7;
    Min = 0x7fffffff;
    scanf("%d", &N);
    for(i = 0; i * 4 <= N; ++i) {
        M = N - i * 4;
        if(M % 7 == 0) {
            if(i + M / 7 <= Min) {
                Min4 = i;
                Min7 = M / 7;
                Min = Min4 + Min7;
            }
        }
    }
    if(Min == 0x7fffffff) {
        printf("-1\n");
    } else {
        for(i = 0; i < Min4; ++i) {
            printf("4");
        }
        for(i = 0; i < Min7; ++i) {
            printf("7");
        }
        printf("\n");
    }
    return 0;
}
