#include <stdio.h>

int main()
{
    int n, L, a;
    scanf("%d %d %d", &n, &L, &a);
    int t, l, preT = 0, preL = 0;
    int ans = 0;
    if(n > 0) {
        scanf("%d %d", &t, &l);
        ans += t / a;
        preT = t;
        preL = l;
    }
    for(int i = 1; i < n; ++i) {
        scanf("%d %d", &t, &l);
        ans += (t - preT - preL) / a;
        preT = t;
        preL = l;
    }
    ans += (L - preT - preL) / a;
    printf("%d\n", ans);
    return 0;
}
