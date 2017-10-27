#include <stdio.h>
#include <string.h>

int main()
{
    int n, cur, max;
    char str[201];
    char flag[26];
    max = 0;
    cur = 0;
    memset(flag, 0, sizeof(flag));
    scanf("%d %s", &n, str);
    for(int i = 0; str[i]; ++i) {
        if(str[i] < 'a') {
            if(max < cur) {
                max = cur;
            }
            cur = 0;
            memset(flag, 0, sizeof(flag));
        } else {
            if(!flag[str[i] - 'a']) {
                flag[str[i] - 'a'] = 1;
                ++cur;
            }
        }
    }
    if(max < cur) {
        max = cur;
    }
    printf("%d\n", max);
    return 0;
}
