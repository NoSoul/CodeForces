#include <stdio.h>

int Cnt[4];

int main()
{
    int n;
    char map[4] = {"ACGT"};
    char str[256];
    scanf("%d %s", &n, str);
    for(int i = 0; str[i]; ++i) {
        if(str[i] == 'A') {
            ++Cnt[0];
        } else if(str[i] == 'C') {
            ++Cnt[1];
        } else if(str[i] == 'G') {
            ++Cnt[2];
        } else if(str[i] == 'T') {
            ++Cnt[3];
        }
    }
    for(int i = 0; i < 4; ++i) {
        if(Cnt[i] > n / 4 || (n & 3)) {
            puts("===");
            return 0;
        }
        Cnt[i] = n / 4 - Cnt[i];
    }
    for(int i = 0; str[i]; ++i) {
        if(str[i] == '?') {
            for(int j = 0; j < 4; ++j) {
                if(Cnt[j]) {
                    --Cnt[j];
                    str[i] = map[j];
                    break;
                }
            }
        }
    }
    puts(str);
    return 0;
}
