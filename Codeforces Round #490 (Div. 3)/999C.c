#include <stdio.h>

char Str[400001];
int Cnt[26];
int Del[26];

int main()
{
    int n, k;
    scanf("%d %d %s", &n, &k, Str);
    for(int i = 0; i < n; ++i) {
        ++Cnt[Str[i] - 'a'];
    }
    for(int i = 0; i < 26; ++i) {
        if(Cnt[i] >= k) {
            Del[i] = k;
            k = 0;
            break;
        } else {
            k -= Cnt[i];
            Del[i] = Cnt[i];
        }
    }
    for(int i = 0; i < n; ++i) {
        if(Del[Str[i] - 'a']) {
            --Del[Str[i] - 'a'];
        } else {
            putchar(Str[i]);
        }
    }
    putchar('\n');
    return 0;
}
