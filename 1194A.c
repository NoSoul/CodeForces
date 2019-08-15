#include <stdio.h>

int main()
{
    int T, n, x;
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &n, &x);
        printf("%d\n", x * 2);
    }
    return 0;
}
