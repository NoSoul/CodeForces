#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        int a, b;
        scanf("%d %d", &a, &b);
        int delta = abs(a - b);
        int table[5] = {0, 1, 1, 2, 2};
        printf("%d\n", delta / 5 + table[delta % 5]);
    }
    return 0;
}
