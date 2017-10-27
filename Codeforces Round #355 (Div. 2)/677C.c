#include <stdio.h>

#define MOD 1000000007
char Str[100001];
int Data[64];

int main()
{
    scanf("%s", Str);
    int len = 0, ans = 1;
    for(int i = 0; i < 64; ++i) {
        for(int j = 0; j < 64; ++j) {
            ++Data[i & j];
        }
    }
    for(int i = 0; Str[i]; ++i, ++len) {
        if(Str[i] >= '0' && Str[i] <= '9') {
            Str[i] -= '0';
        } else if(Str[i] >= 'A' && Str[i] <= 'Z') {
            Str[i] -= 'A' - 10;
        } else if(Str[i] >= 'a' && Str[i] <= 'z') {
            Str[i] -= 'a' - 36;
        } else if(Str[i] == '-') {
            Str[i] = 62;
        } else if(Str[i] == '_') {
            Str[i] = 63;
        }
    }
    for(int i = 0; i < len; ++i) {
        ans = ((long long)ans * Data[(int)Str[i]]) % MOD;
    }
    printf("%d\n", ans);
    return 0;
}
