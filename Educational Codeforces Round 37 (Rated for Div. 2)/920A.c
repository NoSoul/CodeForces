#include <stdio.h>
#include <string.h>

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, k, x;
        char Flag[201];
        scanf("%d %d", &n, &k);
        memset(Flag, 0, sizeof(Flag));
        for(int i = 0; i < k; ++i) {
            scanf("%d", &x);
            Flag[x] = 1;
        }
        int max = 0;
        for(int i = 1; i <= n; ++i) {
            if(Flag[i]) {
                continue;
            }
            int left = i;
            while(--left > 0 && Flag[left] == 0);
            int right = i;
            while(++right <= n && Flag[right] == 0);
            int cur = 0x7f7f7f7f;
            if(left > 0 && cur > i - left) {
                cur = i - left;
            }
            if(right <= n && cur > right - i) {
                cur = right - i;
            }
            if(max < cur) {
                max = cur;
            }
        }
        printf("%d\n", max + 1);
    }
    return 0;
}
