#include <stdio.h>

int main()
{
    int n, b;
    int a[100];
    scanf("%d %d", &n, &b);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        b += a[i];
    }
    for(int i = 0; i < n; ++i) {
        if(a[i]*n > b) {
            puts("-1");
            return 0;
        }
    }
    for(int i = 0; i < n; ++i) {
        printf("%f\n", (b - n * a[i]) * 1.0 / n);
    }
    return 0;
}
