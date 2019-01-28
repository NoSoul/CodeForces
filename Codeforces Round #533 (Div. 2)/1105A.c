#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int a[1000];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int min = 100 * n;
    int ans = -1;
    for(int t = 1; t <= 100; ++t) {
        int cur = 0;
        for(int i = 0; i < n; ++i) {
            if(a[i] != t) {
                cur += abs(a[i] - t) - 1;
            }
        }
        if(min > cur) {
            min = cur;
            ans = t;
        }
    }
    printf("%d %d\n", ans, min);
    return 0;
}
