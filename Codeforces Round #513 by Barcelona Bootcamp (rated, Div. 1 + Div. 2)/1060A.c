#include <stdio.h>

int main()
{
    int n, cnt = 0;
    char s[101];
    scanf("%d", &n);
    scanf("%s", s);
    for(int i = 0; i < n; ++i) {
        cnt += s[i] == '8';
    }
    int ans = cnt;
    if(ans > n / 11) {
        ans = n / 11;
    }
    printf("%d\n", ans);
    return 0;
}
