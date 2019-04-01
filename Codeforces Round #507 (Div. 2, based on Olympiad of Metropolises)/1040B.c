#include <stdio.h>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int cnt = 0;
    if(n <= 2 * k + 1) {
        printf("1\n%d\n", n / 2 + 1);
    } else {
        if(n > 2 * k + 1 && n % (2 * k + 1) <= k && n % (2 * k + 1) > 0) {
            printf("%d\n", 1 + n / (2 * k + 1));
            printf("%d ", 1);
            for(int i = 2 * k + 1; i < n; i += 2 * k + 1) {
                printf("%d ", i + 1);
            }
        } else {
            printf("%d\n", (n + 2 * k) / (2 * k + 1));
            for(int i = k; i < n; i += 2 * k + 1) {
                printf("%d ", i + 1);
            }
        }
    }
    return 0;
}
