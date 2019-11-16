#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        int a[100001];
        int b[100001];
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        for(int i = 0; i < n; ++i) {
            scanf("%d", &b[i]);
            b[i] -= a[i];
        }
        int left = -1, right = -1;
        for(int i = 0; i < n; ++i) {
            if(b[i] != 0) {
                left = i;
                break;
            }
        }
        for(int i = n - 1; i >= 0; --i) {
            if(b[i] != 0) {
                right = i;
                break;
            }
        }
        char check = 1;
        for(int i = left; i <= right; ++i) {
            if(b[i] < 0) {
                check = 0;
                break;
            }
            if(i > left) {
                if(b[i] != b[i - 1]) {
                    check = 0;
                    break;
                }
            }
        }
        printf("%s\n", check ? "YES" : "NO");
    }
    return 0;
}
