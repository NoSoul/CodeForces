#include <stdio.h>

int main()
{
    long long b, d, s, min, Ans;
    while(scanf("%I64d %I64d %I64d", &b, &d, &s) != EOF) {
        min = b;
        if(min > d) {
            min = d;
        }
        if(min > s) {
            min = s;
        }
        b -= min;
        d -= min;
        s -= min;
        if(b == 0 && d == 0 && s == 0) {
            Ans = 0;
        } else if((b != 0 && d == 0 && s == 0) || (b == 0 && d != 0 && s == 0) || (b == 0 && d == 0 && s != 0)) {
            Ans = (b + d + s - 1) * 2;
        } else {
            long long max = b;
            min = b;
            if(max < d) {
                max = d;
            }
            if(max < s) {
                max = s;
            }
            if((min > d && d != 0) || min == 0) {
                min = d;
            }
            if((min > s && s != 0) || min == 0) {
                min = s;
            }
            if(max == min) {
                Ans = max - 1;
            } else {
                Ans = (max - 1) * 2 - min;
            }
        }
        printf("%I64d\n", Ans);
    }
    return 0;
}
