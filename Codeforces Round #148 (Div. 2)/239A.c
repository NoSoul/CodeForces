#include <stdio.h>

int main()
{
    int Y, K, N, i, j, f;
    scanf("%d %d %d", &Y, &K, &N);
    if(Y >= K) {
        j = (Y / K + 1) * K;
    } else {
        j = K;
    }
    for(f = 0, i = j; i <= N; i += K) {
        printf("%d ", i - Y);
        f = 1;
    }
    if(!f) {
        printf("-1");
    }
    return 0;
}
