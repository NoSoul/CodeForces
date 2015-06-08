#include <stdio.h>

int main()
{
    int N, x, y;
    scanf("%d %d %d", &N, &x, &y);
    N >>= 1;
    if((x == N && y == N) || (x == N && y == (N + 1)) || (x == (N + 1) && y == N) || (x == (N + 1) && y == (N + 1))) {
        puts("NO");
    } else {
        puts("YES");
    }
    return 0;
}
