#include <stdio.h>
#include <string.h>

int main()
{
    char str[101];
    scanf("%s", str);
    int len = strlen(str);
    int ans = 0;
    for(int i = 0; i < len; ++i) {
        for(int j = i + 1; j < len; ++j) {
            char cur[101];
            for(int k = i; k < j; ++k) {
                cur[k - i] = str[k];
            }
            cur[j - i] = '\0';
            if(strstr(str + i + 1, cur) != NULL) {
                if(ans < j - i) {
                    ans = j - i;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
