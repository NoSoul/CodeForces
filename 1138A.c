#include <stdio.h>

int main()
{
    int n, t, pret, pre, cur, ans = 0;
    scanf("%d", &n);
    cur = 1;
    pre = -1;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &t);
        if(i) {
            if(t == pret) {
                ++cur;
            } else {
                if(~pre && ans < (pre < cur ? pre : cur)) {
                    ans = (pre < cur ? pre : cur);
                }
                pre = cur;
                cur = 1;
            }
        }
        pret = t;
    }
    if(~pre && ans < (pre < cur ? pre : cur)) {
        ans = pre < cur ? pre : cur;
    }
    printf("%d\n", ans * 2);
    return 0;
}
