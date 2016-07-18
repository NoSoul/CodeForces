#include <stdio.h>

int main()
{
    int n, d, cur = 0, ans = 0;
    char mask[101];
    scanf("%d %d", &n, &d);
    for(int i = 0; i < d; ++i) {
        scanf("%s", mask);
        char lose = 1;
        for(int j = 0; j < n; ++j) {
            lose &= mask[j] == '1';
        }
        if(lose) {
            if(cur > ans) {
                ans = cur;
            }
            cur = 0;
        } else {
            ++cur;
        }
    }
    if(cur > ans) {
        ans = cur;
    }
    printf("%d\n", ans);
    return 0;
}
