#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        char str[101];
        scanf("%d %s", &n, str);
        if(str[0] == '>' || str[n - 1] == '<') {
            puts("0");
        } else {
            int ans = 0;
            for(int i = 0; i < str[i]; ++i) {
                if(str[i] == '>') {
                    ans = i;
                    if(ans > n - i) {
                        ans = n - i;
                    }
                    break;
                }
            }
            for(int i = n - 1; i >= 0; --i) {
                if(str[i] == '<') {
                    if(ans == 0) {
                        ans = i + 1;
                    } else {
                        if(ans > i + 1) {
                            ans = i + 1;
                        }
                    }
                    if(ans > n - i - 1) {
                        ans = n - i - 1;
                    }
                    break;
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
