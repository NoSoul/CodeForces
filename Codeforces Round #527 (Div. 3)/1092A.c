#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        for(int i = 0; i < k; ++i) {
            int m = n / k + (i < n % k ? 1 : 0);
            for(int j = 0; j < m; ++j) {
                putchar('a' + i);
            }
        }
        putchar('\n');
    }
    return 0;
}
