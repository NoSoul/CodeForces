#include <stdio.h>
#include <string.h>

int main()
{
    int cnt = 0;
    char str[101];
    scanf("%s", str);
    int len = strlen(str);
    for(int i = len - 1; i >= 0; --i) {
        if(str[i] == '0') {
            ++cnt;
        } else {
            if(cnt >= 6) {
                puts("yes");
                return 0;
            }
        }
    }
    puts("no");
    return 0;
}
