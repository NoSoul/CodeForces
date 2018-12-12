#include <stdio.h>

int CntS[26], CntT[26];

int main()
{
    int n, cnt = 0;
    char s[51], t[51];
    int ans[10000];
    scanf("%d %s %s", &n, s, t);
    for(int i = 0; s[i]; ++i) {
        ++CntS[s[i] - 'a'];
    }
    for(int i = 0; t[i]; ++i) {
        ++CntT[t[i] - 'a'];
    }
    for(int i = 0; i < 26; ++i) {
        if(CntS[i] != CntT[i]) {
            puts("-1");
            return 0;
        }
    }
    for(int i = 0; i < n; ++i) {
        if(s[i] != t[i]) {
            for(int j = i + 1; j < n; ++j) {
                if(s[j] == t[i]) {
                    for(int k = j - 1; k >= i; --k) {
                        char temp = s[k + 1];
                        s[k + 1] = s[k];
                        s[k] = temp;
                        ans[cnt++] = k + 1;
                    }
                    break;
                }
            }
        }
    }
    printf("%d\n", cnt);
    for(int i = 0; i < cnt; ++i) {
        printf("%d ", ans[i]);
    }
    return 0;
}
