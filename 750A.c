#include <stdio.h>

int main()
{
    int n, k, sum = 0;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; ++i) {
        if(sum + 5 * i + k > 240) {
            printf("%d\n", i - 1);
            return 0;
        }
        sum += 5 * i;
    }
    printf("%d\n", n);
    return 0;
}
