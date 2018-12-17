#include <stdio.h>

int main()
{
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    for(int i = 0; i * a <= n; ++i) {
        if((n - i * a) % b == 0) {
            printf("YES\n%d %d\n", i, (n - i * a) / b);
            return 0;
        }
    }
    puts("NO");
    return 0;
}
