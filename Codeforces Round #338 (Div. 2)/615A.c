#include <stdio.h>

char Flag[101];

int main()
{
    int N, M, x, y, i;
    scanf("%d %d", &N, &M);
    while(N--) {
        scanf("%d", &x);
        while(x--) {
            scanf("%d", &y);
            Flag[y] = 1;
        }
    }
    for(i = 1; i <= M; ++i) {
        if(!Flag[i]) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}
