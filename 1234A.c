#include <stdio.h>

int main()
{
    int q;
    scanf("%d", &q);
    while(q--) {
        int n;
        scanf("%d", &n);
        int a[100];
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        printf("%d\n", sum / n + (sum % n == 0 ? 0 : 1));
    }
    return 0;
}
