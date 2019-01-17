#include <stdio.h>

int main()
{
    int n, x, y, remain = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &x);
        remain += x;
    }
    for(int i = 0; i < n; ++i) {
        scanf("%d", &y);
        remain -= y;
    }
    puts(remain < 0 ? "No" : "Yes");
    return 0;
}
