#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int n;
    int a[1000];
    long long ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp);
    for(int i = 1; i < n; ++i) {
        ans += a[i] - a[i - 1] - 1;
    }
    printf("%I64d\n", ans);
    return 0;
}
