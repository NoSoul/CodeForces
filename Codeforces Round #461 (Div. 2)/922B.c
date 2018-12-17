#include <stdio.h>


int main()
{
    int n;
    scanf("%d", &n);
    int ans = 0;
    for(int a = 1; a <= n; ++a) {
        for(int b = a + 1; b <= n; ++b) {
            int c = a ^ b;
            if(a + b > c && a + c > b && c > b && c <= n) {
                ++ans;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
