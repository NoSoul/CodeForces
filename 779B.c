#include <stdio.h>
#include <string.h>

int main()
{
    char str[11];
    int k, ans = 0;
    scanf("%s %d", str, &k);
    while(1) {
        int len = strlen(str);
        int cnt = 0;
        for(int i = len - 1; i >= 0; --i) {
            if(str[i] != '0') {
                str[i] = '0';
                break;
            } else {
                if(++cnt == k) {
                    printf("%d\n", ans);
                    return 0;
                }
            }
        }
        ++ans;
        str[len - 1] = '\0';
        if(len == 1) {
            break;
        }
    }
    printf("%d\n", ans - 1);
    return 0;
}
