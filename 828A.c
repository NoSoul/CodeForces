#include <stdio.h>

int main()
{
    int n, a, b, c, t, ans;
    ans = c = 0;
    scanf("%d %d %d", &n, &a, &b);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &t);
        if(t == 2) {
            if(b) {
                --b;
            } else {
                ans += 2;
            }
        } else {
            if(a) {
                --a;
            } else {
                if(b) {
                    --b;
                    ++c;
                } else {
                    if(c) {
                        --c;
                    } else {
                        ++ans;
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
