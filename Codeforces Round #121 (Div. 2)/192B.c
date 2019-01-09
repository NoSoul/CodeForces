#include <stdio.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int n;
    int a[1000];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    if(n > 1) {
        a[1] = min(a[1], a[0]);
        for(int i = 2; i < n; ++i) {
            a[i] = min(a[i], max(a[i - 1], a[i - 2]));
        }
    }
    printf("%d\n", a[n - 1]);
    return 0;
}
