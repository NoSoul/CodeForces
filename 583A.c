#include <stdio.h>

char H[51];
char V[51];

int main()
{
    int N, i, x, y;
    scanf("%d", &N);
    for(i = 1; i <= N * N; ++i) {
        scanf("%d %d", &x, &y);
        if(!H[x] && !V[y]) {
            H[x] = 1;
            V[y] = 1;
            printf("%d ", i);
        }
    }
    puts("");
    return 0;
}
