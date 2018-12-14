#include <stdio.h>

int Cnt[26];

int main()
{
    int n;
    char str[100001];
    scanf("%d %s", &n, str);
    for(int i = 0; str[i]; ++i) {
        ++Cnt[str[i] - 'a'];
    }
    for(int i = 0; i < 26; ++i) {
        for(int j = 0; j < Cnt[i]; ++j) {
            putchar('a' + i);
        }
    }
    return 0;
}
