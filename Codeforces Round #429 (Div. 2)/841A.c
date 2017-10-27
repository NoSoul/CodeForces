#include <stdio.h>

int Cnt[26];

int main()
{
    int n, k;
    char Str[101];
    scanf("%d %d %s", &n, &k, Str);
    for(int i = 0; Str[i]; ++i) {
        ++Cnt[Str[i] - 'a'];
    }
    for(int i = 0; i < 26; ++i) {
        if(Cnt[i] > k) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}
