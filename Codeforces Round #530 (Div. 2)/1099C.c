#include <stdio.h>
#include <string.h>

int Cnt[2];

int main()
{
    int k;
    char str[201];
    scanf("%s %d", str, &k);
    for(int i = 0; str[i]; ++i) {
        if(str[i] == '?') {
            ++Cnt[0];
        } else if(str[i] == '*') {
            ++Cnt[1];
        }
    }
    int len = strlen(str) - Cnt[0] * 2 - Cnt[1] * 2;
    if(k < len) {
        puts("Impossible");
    } else {
        if(Cnt[1]) {
            int repatTime = k - len;
            for(int i = 0; str[i]; ++i) {
                if(str[i + 1] == '?') {
                    ++i;
                } else if(str[i + 1] == '*') {
                    for(int j = 0; j < repatTime; ++j) {
                        putchar(str[i]);
                    }
                    repatTime = 0;
                    ++i;
                } else {
                    putchar(str[i]);
                }
            }
            putchar('\n');
        } else {
            int maxLen = len + Cnt[0];
            if(k > maxLen) {
                puts("Impossible");
            } else {
                for(int i = 0; str[i]; ++i) {
                    if(str[i + 1] != '?') {
                        putchar(str[i]);
                    } else {
                        if(maxLen > k) {
                            --maxLen;
                        } else {
                            putchar(str[i]);
                        }
                        ++i;
                    }
                }
                putchar('\n');
            }
        }
    }
    return 0;
}
