#include <stdio.h>
#include <string.h>

int main()
{
    char s[51];
    scanf("%s", s);
    int cnt = 0;
    for(int i = 0; s[i]; ++i) {
        cnt += s[i] == 'a';
    }
    unsigned ans = cnt + cnt - 1;
    if(ans > strlen(s)) {
        ans = strlen(s);
    }
    printf("%d\n", ans);
    return 0;
}
