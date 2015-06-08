#include <stdio.h>

int main()
{
    int N, i, M, j;
    scanf("%d", &N);
    if(N < 4) {
        puts("NO");
        return 0;
    }
    puts("YES");
    if(N & 1) {
        puts("5 - 2 = 3");
        puts("3 - 1 = 2");
        puts("2 * 3 = 6");
        puts("6 * 4 = 24");
        M = N - 5;
        M >>= 1;
        for(i = 0, j = 7; i < M; ++i, j += 2) {
            printf("%d - %d = 1\n", j, j - 1);
            puts("1 * 24 = 24");
        }
    } else {
        puts("1 * 2 = 2");
        puts("2 * 3 = 6");
        puts("6 * 4 = 24");
        M = N - 4;
        M >>= 1;
        for(i = 0, j = 6; i < M; ++i, j += 2) {
            printf("%d - %d = 1\n", j, j - 1);
            puts("1 * 24 = 24");
        }
    }
    return 0;
}
