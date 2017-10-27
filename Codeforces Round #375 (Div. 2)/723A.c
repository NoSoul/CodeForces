#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[3];
    for(int i = 0; i < 3; ++i) {
        scanf("%d", &a[i]);
    }
    int ans = 300;
    for(int i = 1; i < 101; ++i) {
        int cur = abs(i - a[0]) + abs(i - a[1]) + abs(i - a[2]);
        if(cur < ans) {
            ans = cur;
        }
    }
    printf("%d\n", ans);
    return 0;
}
