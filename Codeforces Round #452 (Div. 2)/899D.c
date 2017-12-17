#include <stdio.h>

int Cnt[10];

int main()
{
    int table[] = {999999999, 99999999, 9999999, 999999, 99999, 9999, 999, 99, 9};
    int n, reamin = 0, ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < 9; ++i) {
        if(n + n - 1 >= table[i]) {
            reamin = table[i];
            break;
        }
    }
    if(reamin == 0) {
        printf("%d\n", n * (n - 1) / 2);
        return 0;
    }
    for(int i = 0; i < 9; ++i) {
        long long expect = (long long)(reamin + 1) * i + reamin;
        if(n + n - 1 >= expect) {
            if(expect <= n) {
                ans += expect / 2;
            } else {
                ans += n - expect / 2;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
