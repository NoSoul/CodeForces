#include <stdio.h>

int main()
{
    int n, a, b, ans = 0;
    char str[200001];
    scanf("%d %d %d %s", &n, &a, &b, str);
    int cur = 0;
    for(int i = 0; i < n; ++i) {
        if(str[i] == '.') {
            ++cur;
        } else {
            int min = a < b ? a : b;
            int support = 2 * min + (a != b);
            if(support > cur) {
                ans += cur;
                a -= cur / 2;
                b -= cur / 2;
                if(cur & 1) {
                    if(a > b) {
                        --a;
                    } else {
                        --b;
                    }
                }
            } else {
                ans += support;
                a -= min;
                b -= min;
                if(a > b) {
                    --a;
                } else if(b > a) {
                    --b;
                }
                cur -= support;
                cur /= 2;
                support = a > b ? a : b;
                if(support > cur) {
                    support = cur;
                }
                ans += support;
                if(a > b) {
                    a -= support;
                } else if(b > a) {
                    b -= support;
                }
            }
            cur = 0;
        }
    }
    int min = a < b ? a : b;
    int support = 2 * min + (a != b);
    if(support > cur) {
        ans += cur;
        a -= cur / 2;
        b -= cur / 2;
        if(cur & 1) {
            if(a > b) {
                --a;
            } else {
                --b;
            }
        }
    } else {
        ans += support;
        a -= min;
        b -= min;
        if(a > b) {
            --a;
        } else if(b > a) {
            --b;
        }
        cur -= support;
        cur /= 2;
        support = a > b ? a : b;
        if(support > cur) {
            support = cur;
        }
        ans += support;
        if(a > b) {
            a -= support;
        } else if(b > a) {
            b -= support;
        }
    }
    printf("%d\n", ans);
    return 0;
}
