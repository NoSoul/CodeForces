#include <stdio.h>

int main()
{
    int n, p;
    char a[40];
    char str[9];
    long long ans = 0;
    scanf("%d %d", &n, &p);
    for(int i = 0; i < n; ++i) {
        scanf("%s", str);
        if(str[4] == '\0') {
            a[i] = 0;
        } else {
            a[i] = 1;
        }
    }
    long long pre = 0;
    for(int i = n - 1; i >= 0; --i) {
        long long cur;
        if(a[i]) {
            cur = pre * 2 + 1;
            ans += pre * p + p / 2;
        } else {
            cur = pre * 2;
            ans += pre * p;
        }
        pre = cur;
    }
    printf("%I64d\n", ans);
    return 0;
}
