#include <stdio.h>

int main()
{
    int n;
    int a[200001];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int expect = a[n - 1];
    long long ans = 0;
    for(int i = n - 1; i >= 0; --i) {
        if(a[i] >= expect) {
            ans += expect;
            if(expect) {
                --expect;
            }
        } else {
            ans += a[i];
            expect = a[i] - 1;
        }
    }
    printf("%I64d\n", ans);
    return 0;
}
