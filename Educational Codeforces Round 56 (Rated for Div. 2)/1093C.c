#include <stdio.h>

int main()
{
    int n;
    long long b, min = 0;
    long long a[200001];
    scanf("%d", &n);
    for(int i = 1; i <= n / 2; ++i) {
        scanf("%I64d", &b);
        if(i == 1) {
            a[1] = min;
            a[n] = b - min;
        } else {
            if(b - min > a[n - i + 2]) {
                a[n - i + 1] = a[n - i + 2];
                a[i] = b - a[n - i + 1];
                min = a[i];
            } else {
                a[i] = min;
                a[n - i + 1] = b - min;
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        printf("%I64d ", a[i]);
    }
    return 0;
}
