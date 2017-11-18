#include <stdio.h>

int GCD(int a, int b)
{
    int temp;
    while(b) {
        temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

int main()
{
    int n, ans = 0;
    int a[2000];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        ans += a[i] != 1;
    }
    if(n == 1) {
        puts(a[0] == 1 ? "0" : "-1");
        return 0;
    }
    for(int i = 1; i < n; ++i) {
        if(GCD(a[i - 1], a[i]) == 1) {
            printf("%d\n", ans);
            return 0;
        }
    }
    int min = 2 * n;
    for(int i = 0; i < n - 1; ++i) {
        int gcd = a[i];
        for(int j = i + 1; j < n; ++j) {
            gcd = GCD(gcd, a[j]);
            if(gcd == 1) {
                int cur = j - i - 1;
                if(min > cur) {
                    min = cur;
                }
            }
        }
    }
    if(min != 2 * n) {
        printf("%d\n", min + n);
    } else {
        puts("-1");
    }
    return 0;
}
