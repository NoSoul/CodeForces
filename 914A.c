#include <stdio.h>
#include <math.h>

int main()
{
    int n, a, ans = -1e6;
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &a);
        int m = sqrt(a);
        if(m * m != a) {
            if(ans < a) {
                ans = a;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
