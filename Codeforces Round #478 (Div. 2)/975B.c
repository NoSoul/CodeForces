#include <stdio.h>
#include <string.h>

int main()
{
    int a[14];
    int b[14];
    for(int i = 0; i < 14; ++i) {
        scanf("%d", &a[i]);
    }
    long long ans = 0;
    for(int i = 0; i < 14; ++i) {
        if(a[i]) {
            memcpy(b, a, sizeof(a));
            b[i] = 0;
            for(int j = 0; j < 14; ++j) {
                b[(i + j + 1) % 14] += a[i] / 14 + (a[i] % 14 > j);
            }
            long long cur = 0;
            for(int j = 0; j < 14; ++j) {
                if(!(b[j] & 1)) {
                    cur += b[j];
                }
            }
            if(ans < cur) {
                ans = cur;
            }
        }
    }
    printf("%I64d\n", ans);
    return 0;
}
