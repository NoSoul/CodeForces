#include <stdio.h>
#include <string.h>

int main()
{
    char str[5001];
    int cnt[3];
    memset(cnt, 0, sizeof(cnt));
    scanf("%s", str);
    for(int i = 0; str[i]; ++i) {
        if(i) {
            if(str[i] < str[i - 1]) {
                puts("NO");
                return 0;
            }
        }
        ++cnt[str[i] - 'a'];
    }
    if(cnt[0] > 0 && cnt[1] > 0 && (cnt[2] == cnt[0] || cnt[2] == cnt[1])) {
        puts("YES");
    } else {
        puts("NO");
    }
    return 0;
}
