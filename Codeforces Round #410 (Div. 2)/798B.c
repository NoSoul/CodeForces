#include <stdio.h>
#include <string.h>

int main()
{
    int n, ans = 50 * 50 * 50;
    char str[50][51];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%s", str[i]);
    }
    int len = strlen(str[0]);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < len; ++j) {
            int cur = 0;
            for(int k = 0; k < n; ++k) {
                char fail = 1;
                for(int l = 0; l < len; ++l) {
                    char check = 1;
                    for(int m = 0; m < len; ++m) {
                        if(str[i][(j + m) % len] != str[k][(l + m) % len]) {
                            check = 0;
                            break;
                        }
                    }
                    if(check) {
                        fail = 0;
                        cur += l;
                        break;
                    }
                }
                if(fail) {
                    puts("-1");
                    return 0;
                }
            }
            if(ans > cur) {
                ans = cur;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
