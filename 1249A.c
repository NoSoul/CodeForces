#include <stdio.h>

int main()
{
    int q;
    scanf("%d", &q);
    while(q--) {
        int n;
        scanf("%d", &n);
        int a[100];
        for(int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if(a[i] > a[j]) {
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
        int ans = 1;
        for(int i = 1; i < n; ++i) {
            if(a[i] == a[i - 1] + 1) {
                ans = 2;
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
