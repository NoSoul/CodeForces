#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, a;
        scanf("%d", &n);
        int max[2] = {0};
        for(int i = 0; i < n; ++i) {
            scanf("%d", &a);
            if(a > max[1]) {
                max[1] = a;
                if(max[1] > max[0]) {
                    int temp = max[0];
                    max[0] = max[1];
                    max[1] = temp;
                }
            }
        }
        int ans = max[1] - 1;
        if(ans > n - 2) {
            ans = n - 2;
        }
        printf("%d\n", ans);
    }
    return 0;
}
