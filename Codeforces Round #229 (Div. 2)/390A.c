#include <stdio.h>

int Hashx[101], Hashy[101];

int main()
{
    int N, i, x, y;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d %d", &x, &y);
        Hashx[x] = 1;
        Hashy[y] = 1;
    }
    x = y = 0;
    for(i = 0; i < 101; ++i) {
        x += Hashx[i];
    }
    for(i = 0; i < 101; ++i) {
        y += Hashy[i];
    }
    printf("%d\n", x < y ? x : y);
    return 0;
}
