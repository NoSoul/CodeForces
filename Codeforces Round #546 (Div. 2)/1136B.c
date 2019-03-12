#include <stdio.h>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    if(k == 1 || k == n) {
        printf("%d\n", n * 3);
    } else {
        if(k <= n / 2) {
            printf("%d\n", n * 3 + k - 1);
        } else {
            printf("%d\n", n * 4 - k);
        }
    }
    return 0;
}
