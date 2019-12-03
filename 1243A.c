#include <stdio.h>

int Min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    int k;
    scanf("%d", &k);
    while(k--) {
        int n;
        scanf("%d", &n);
        int a[1000];
        for(int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if(a[i] < a[j]) {
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            int cur = Min(i + 1, a[i]);
            if(ans < cur) {
                ans = cur;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
