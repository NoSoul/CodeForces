#include <stdio.h>

int Cnt[26];

int main()
{
    int n;
    char str[21];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%s", str);
        ++Cnt[str[0] - 'a'];
    }
    int ans = 0;
    for(int i = 0; i < 26; ++i) {
        if(Cnt[i] > 2) {
            int a = Cnt[i] / 2;
            int b = Cnt[i] - a;
            ans += a * (a - 1) / 2 + b * (b - 1) / 2;
        }
    }
    printf("%d\n", ans);
    return 0;
}
