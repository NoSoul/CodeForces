#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    int a[200000];
    int ans[200000];
    memset(ans, -1, sizeof(ans));
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; ++i) {
        if(a[i] == 0) {
            ans[i] = 0;
            for(int j = i - 1; j >= 0; --j) {
                int cur = i - j;
                if(ans[j] == -1) {
                    ans[j] = cur;
                } else {
                    if(cur > ans[j]) {
                        break;
                    }
                    ans[j] = cur;
                }
            }
            int j;
            for(j = i + 1; a[j] != 0 && j < n; ++j) {
                ans[j] = j - i;
            }
            i = j - 1;
        }
    }
    for(int i = 0; i < n; ++i) {
        printf("%d ", ans[i]);
    }
    puts("");
    return 0;
}
