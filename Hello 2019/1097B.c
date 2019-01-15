#include <stdio.h>

int main()
{
    int n;
    int a[15];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < (1 << n); ++i) {
        int cur = 0;
        for(int j = 0; j < n; ++j) {
            if(i & (1 << j)) {
                cur += a[j];
            } else {
                cur -= a[j];
            }
        }
        if(cur % 360 == 0) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}
