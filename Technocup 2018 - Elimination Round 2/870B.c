#include <stdio.h>

int Max(int a, int b)
{
    return a > b ? a : b;
}

int Min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    int n, k;
    int a[100000];
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int max = a[0], min = a[0];
    for(int i = 0; i < n; ++i) {
        max = Max(max, a[i]);
        min = Min(min, a[i]);
    }
    if(k == 1) {
        printf("%d\n", min);
    } else if(k >= 3) {
        printf("%d\n", max);
    } else {
        int ans = min;
        int conMin = a[0];
        for(int i = 0; i < n; ++i) {
            conMin = Min(conMin, a[i]);
            ans = Max(ans, conMin);
        }
        conMin = a[n - 1];
        ans = Max(ans, conMin);
        for(int i = n - 1; i > 0; --i) {
            conMin = Min(conMin, a[i]);
            ans = Max(ans, conMin);
        }
        printf("%d\n", ans);
    }
    return 0;
}
