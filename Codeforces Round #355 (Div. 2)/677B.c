#include <stdio.h>

int A[100000];

int main()
{
    int n, h, k, i, remain = 0;
    long long ans = 0;
    scanf("%d %d %d", &n, &h, &k);
    for(i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
    }
    i = 0;
    while(i < n) {
        while(remain + A[i] <= h) {
            remain += A[i];
            if(++i == n) {
                break;
            }
        }
        if(remain >= k) {
            int cnt = remain / k;

            remain -= cnt * k;
            ans += cnt;
        } else {
            remain = 0;
            ++ans;
        }
    }
    if(remain) {
        ++ans;
    }
    printf("%I64d\n", ans);
    return 0;
}
