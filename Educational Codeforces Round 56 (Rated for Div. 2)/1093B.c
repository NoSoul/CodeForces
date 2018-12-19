#include <stdio.h>
#include <string.h>

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        char str[1001];
        scanf("%s", str);
        int len = strlen(str);
        if(len == 1) {
            puts("-1");
        } else {
            int cnt[26];
            memset(cnt, 0, sizeof(cnt));
            for(int i = 0; str[i]; ++i) {
                ++cnt[str[i] - 'a'];
            }
            for(int i = 0; i < 26; ++i) {
                if(cnt[i] == len) {
                    printf("-1");
                    break;
                }
                for(int j = 0; j < cnt[i]; ++j) {
                    putchar('a' + i);
                }
            }
            putchar('\n');
        }
    }
    return 0;
}
