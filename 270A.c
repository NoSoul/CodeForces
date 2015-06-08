#include <stdio.h>

int main()
{
    int T, a;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &a);
        puts(360 % (180 - a) ? "NO" : "YES");
    }
    return 0;
}

