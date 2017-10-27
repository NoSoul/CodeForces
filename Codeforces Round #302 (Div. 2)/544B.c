#include <stdio.h>

int main()
{
    int N, K, Max;
    scanf("%d %d", &N, &K);
    Max = ((N + 1) / 2) * ((N + 1) / 2) + (N / 2) * (N / 2);
    if(K > Max) {
        puts("NO");
        return 0;
    }
    puts("YES");
    int i, j;
    for(i = 0; i < N; ++i) {
        for(j = 0; j < N; ++j) {
            if(K) {
                if(((i & 1) && (j & 1)) || (!(i & 1) && !(j & 1))) {
                    putchar('L');
                    --K;
                } else {
                    putchar('S');
                }
            } else {
                putchar('S');
            }
        }
        putchar('\n');
    }
    return 0;
}
