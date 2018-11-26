#include <stdio.h>

int Cnt[26];

int main()
{
    int n;
    char str[1001];
    scanf("%d %s", &n, str);
    for(int i = 0; str[i] != '\0'; ++i) {
        ++Cnt[str[i] - 'a'];
    }
    int cur = 0;
    for(int i = 0; i < 26; ++i) {
        cur += Cnt[i] != 0;
    }
    if(cur == 1) {
        puts("NO");
    } else {
        puts("YES");
        for(int i = 1; str[i] != '\0'; ++i) {
            if(str[i] != str[i - 1]) {
                printf("%c%c\n", str[i - 1], str[i]);
                break;
            }
        }
    }
    return 0;
}
