#include <stdio.h>
#include <string.h>

int Cnt[26];

int main()
{
    int n, k, ans = 0;
    char str[100001];
    scanf("%d %d", &n, &k);
    scanf("%s", str);
    for(int i = 0; i < n; ++i) {
        ++Cnt[str[i] - 'A'];
    }
    ans = Cnt[0];
    for(int i = 1; i < k; ++i) {
        if(ans > Cnt[i]) {
            ans = Cnt[i];
        }
    }
    printf("%d\n", ans * k);
    return 0;
}
