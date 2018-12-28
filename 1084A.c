#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int a[101];
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    int min = 0x7f7f7f7f;
    for(int x = 1; x < 101; ++x) {
        int cur = 0;
        for(int i = 1; i <= n; ++i) {
            cur += (abs(x - i) + abs(i - 1) + abs(1 - x)) * a[i] * 2;
        }
        if(min > cur) {
            min = cur;
        }
    }
    printf("%d\n", min);
    return 0;
}
