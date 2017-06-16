#include <stdio.h>
#include <string.h>

int main()
{
    char str[16];
    scanf("%s", str);
    int len = strlen(str);
    int cnt = 0;
    for(int i = 0; i < (len + 1) / 2; ++i) {
        if(str[i] != str[len - 1 - i]) {
            ++cnt;
        }
    }
    if(cnt == 1) {
        puts("YES");
    } else if(cnt == 0) {
        puts((len & 1) ? "YES" : "NO");
    } else {
        puts("NO");
    }
    return 0;
}
