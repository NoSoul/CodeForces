#include <stdio.h>
#include <string.h>

int main()
{
    char Str[1000001];
    scanf("%s", Str);
    int len = strlen(Str);
    int callen = 0, pos, ans = 0;
    int MOD = 1e9 + 7;
    for(int i = len - 1; i >= 0; --i) {
        if(Str[i] == 'b') {
            while(i >= 0 && Str[i] == 'b') {
                ++callen;
                --i;
                pos = i;
            }
            break;
        }
    }
    if(callen) {
        for(int i = pos; i >= 0; --i) {
            if(Str[i] == 'a') {
                ans = (ans + callen) % MOD;
                callen = (callen * 2) % MOD;
            } else {
                callen = (callen + 1) % MOD;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
