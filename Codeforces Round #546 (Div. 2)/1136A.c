#include <stdio.h>

int main()
{
    int n, k;
    int l[100], r[100];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d %d", &l[i], &r[i]);
    }
    scanf("%d", &k);
    for(int i = 0; i < n; ++i) {
        if(k >= l[i] && k <= r[i]) {
            printf("%d\n", n - i);
            return 0;
        }
    }
    return 0;
}
