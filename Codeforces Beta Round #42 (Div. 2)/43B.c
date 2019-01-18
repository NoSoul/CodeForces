#include <stdio.h>

int Cnt[52];

int main()
{
    char s1[201];
    char s2[201];
    fgets(s1, 201, stdin);
    fgets(s2, 201, stdin);
    for(int i = 0; s1[i]; ++i) {
        if(s1[i] >= 'a' && s1[i] <= 'z') {
            ++Cnt[s1[i] - 'a'];
        } else if(s1[i] >= 'A' && s1[i] <= 'Z') {
            ++Cnt[s1[i] - 'A' + 26];
        }
    }
    for(int i = 0; s2[i]; ++i) {
        if(s2[i] >= 'a' && s2[i] <= 'z') {
            if(Cnt[s2[i] - 'a']) {
                --Cnt[s2[i] - 'a'];
            } else {
                puts("NO");
                return 0;
            }
        } else if(s2[i] >= 'A' && s2[i] <= 'Z') {
            if(Cnt[s2[i] - 'A' + 26]) {
                --Cnt[s2[i] - 'A' + 26];
            } else {
                puts("NO");
                return 0;
            }
        }
    }
    puts("YES");
    return 0;
}
