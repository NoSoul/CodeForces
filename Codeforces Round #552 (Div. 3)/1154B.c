#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int a[100];
    scanf("%d", &n);
    int min = 100, max = 1;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if(min > a[i]) {
            min = a[i];
        }
        if(max < a[i]) {
            max = a[i];
        }
    }
    int ans = 0x7fffffff;
    for(int i = min; i <= max; ++i) {
        int d = 0;
        char check = 1;
        for(int j = 0; j < n; ++j) {
            int cur = a[j] - i;
            if(cur) {
                if(d == 0) {
                    d = cur;
                } else {
                    if(abs(d) != abs(cur)) {
                        check = 0;
                        break;
                    }
                }
            }
        }
        if(check) {
            if(ans > abs(d)) {
                ans = abs(d);
            }
        }
    }
    printf("%d\n", ans == 0x7fffffff ? -1 : ans);
    return 0;
}
