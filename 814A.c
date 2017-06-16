#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}


int main()
{
    int a[100], b[100];
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < k; ++i) {
        scanf("%d", &b[i]);
    }
    qsort(b, k, sizeof(int), cmp);
    for(int i = 0; i < n; ++i) {
        if(a[i] == 0 && k) {
            a[i] = b[k - 1];
            --k;
        }
    }
    for(int i = 1; i < n; ++i) {
        if(a[i] < a[i - 1]) {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}
