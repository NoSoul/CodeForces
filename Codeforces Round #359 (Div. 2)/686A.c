#include <stdio.h>

int main()
{
    int n, d, ans = 0;
    long long x;
    char op[2];
    scanf("%d %I64d", &n, &x);
    for(int i = 0; i < n; ++i) {
        scanf("%s %d", op, &d);
        if(op[0] == '+') {
            x += d;
        } else {
            if(x >= d) {
                x -= d;
            } else {
                ++ans;
            }
        }
    }
    printf("%I64d %d\n", x, ans);
    return 0;
}
