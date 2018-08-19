#include <stdio.h>

int Cnt[26];

int main()
{
    int n;
    char str[100001];
    scanf("%d %s", &n, str);
    for(int i = 0; i < n; ++i) {
        ++Cnt[str[i] - 'a'];
    }
    if(n == 1) {
        puts("Yes");
        return 0;
    }
    for(int i = 0; i < 26; ++i) {
        if(Cnt[i] >= 2) {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}
