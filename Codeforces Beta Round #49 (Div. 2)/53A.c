#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    char s[101], t[101], ans[101] = {0};
    scanf("%s %d", s, &n);
    for(int i = 0; i < n; ++i) {
        scanf("%s", t);
        if(strncmp(s, t, strlen(s)) == 0) {
            if(ans[0] == '\0' || strcmp(ans, t) > 0) {
                strcpy(ans, t);
            }
        }
    }
    if(ans[0] == '\0') {
        strcpy(ans, s);
    }
    printf("%s\n", ans);
    return 0;
}
