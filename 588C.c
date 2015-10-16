#include <stdio.h>

#define MAXN    1000032

int W[MAXN];

int main()
{
    int N, i, j, Num, Ans = 0;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d", &Num);
        ++W[Num];
    }
    for(i = 0; i < MAXN; ++i) {
        for(j = 30; j > 0; --j) {
            if(1 << j & W[i]) {
                W[i] -= 1 << j;
                ++W[i + j];
            }
        }
        if(W[i]) {
            ++Ans;
        }
    }
    printf("%d\n", Ans);
    return 0;
}
