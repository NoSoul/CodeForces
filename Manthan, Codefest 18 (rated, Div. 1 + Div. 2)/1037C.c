#include <stdio.h>

int main()
{
    int n, ans = 0;
    char a[1000001];
    char b[1000001];
    scanf("%d %s %s", &n, a, b);
    for(int i = 0; i < n; ++i) {
        if(a[i] != b[i]) {
            if(i + 1 < n) {
                if(a[i + 1] != b[i + 1] && a[i + 1] == b[i] && a[i] == b[i + 1]) {
                    ++ans;
                    ++i;
                } else {
                    ++ans;
                }
            } else {
                ++ans;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
