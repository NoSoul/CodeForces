#include <stdio.h>

int main()
{
    int l, r, x, y, k;
    scanf("%d %d %d %d %d", &l, &r, &x, &y, &k);
    for(int i = x; i <= y; ++i) {
        if((long long)k * i >= l && (long long)k * i <= r) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}
