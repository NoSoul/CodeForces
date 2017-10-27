#include <stdio.h>
#include <string.h>

char Str[50001];

int main()
{
    scanf("%s", Str);
    int Cnt[27];
    int len = strlen(Str);
    char Ans = 0;
    for(int i = 0; i + 26 <= len; ++i) {
        memset(Cnt, 0, sizeof(Cnt));
        for(int j = i; j < i + 26; ++j) {
            if(Str[j] != '?') {
                ++Cnt[Str[j] - 'A'];
            } else {
                ++Cnt[26];
            }
        }
        int need = 0;
        for(int k = 0; k < 26; ++k) {
            if(Cnt[k] == 0) {
                ++need;
            }
        }
        if(need == Cnt[26]) {
            Ans = 1;
            for(int k = 0; k < 26; ++k) {
                if(Cnt[k] == 0) {
                    for(int j = i; j < i + 26; ++j) {
                        if(Str[j] == '?') {
                            Str[j] = k + 'A';
                            break;
                        }
                    }
                }
            }
            for(int j = 0; j < len; ++j) {
                if(Str[j] == '?') {
                    Str[j] = 'A';
                }
            }
            break;
        }
    }
    if(Ans == 0) {
        puts("-1");
    } else {
        puts(Str);
    }
    return 0;
}
