#include <stdio.h>

int main()
{
    int q, n;
    scanf("%d", &q);
    while(q--) {
        scanf("%d", &n);
        if(n == 4 || n == 6 || n == 9) {
            puts("1");
        } else if(n == 8 || n == 10) {
            puts("2");
        } else if(n >= 12) {
            int table[4] = {3, 2, 3, 2};
            printf("%d\n", table[n & 3] + ((n - 12) >> 2));
        } else {
            puts("-1");
        }

    }
    return 0;
}
