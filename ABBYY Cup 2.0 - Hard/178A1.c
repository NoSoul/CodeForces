#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    int A[100001];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
    }
    long long ans = 0;
    for(int i = 0; i < n - 1; ++i) {
        ans += A[i];
        for(int t = log2(n) + 1; t >= 0; --t) {
            if(i + (1 << t) < n) {
                A[i + (1 << t)] += A[i];
                break;
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
