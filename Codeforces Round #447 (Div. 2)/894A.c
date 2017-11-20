#include <stdio.h>
#include <string.h>

int main()
{
    int ans = 0;
    char str[101];
    scanf("%s", str);
    int len = strlen(str);
    for(int i = 0; i < len - 2; ++i) {
        for(int j = i + 1; j < len - 1; ++j) {
            for(int k = j + 1; k < len; ++k) {
                ans += str[i] == 'Q' && str[j] == 'A' && str[k] == 'Q';
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
