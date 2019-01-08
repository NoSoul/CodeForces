#include <stdio.h>

int main()
{
    int n, x, a, sum;
    scanf("%d %d", &n, &x);
    sum = n - 1;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        sum += a;
    }
    puts(sum == x ? "YES" : "NO");
    return 0;
}
