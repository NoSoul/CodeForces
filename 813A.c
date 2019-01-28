#include <stdio.h>

int main()
{
    int n, m;
    int a[1000];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if(i) {
            a[i] += a[i - 1];
        }
    }
    scanf("%d", &m);
    int pos = 0;
    int ans = -1;
    while(m--) {
        int l, r;
        scanf("%d %d", &l, &r);
        while(a[pos] <= r) {
            if(a[pos] < l) {
                ans = l;
            } else {
                ans = a[pos];
            }
            if(++pos == n) {
                break;
            }
        }
        if(pos == n) {
            break;
        }
    }
    if(pos == n) {
        printf("%d\n", ans);
    } else {
        puts("-1");
    }
    return 0;
}
