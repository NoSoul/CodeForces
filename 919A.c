#include <stdio.h>

int main()
{
    int n, m, a, b;
    float ans = 0;
    scanf("%d %d", &n, &m);
    while(n--) {
        scanf("%d %d", &a, &b);
        if(ans == 0) {
            ans = 1.0 * a * m / b;
        } else {
            if(ans > 1.0 * a * m / b) {
                ans = 1.0 * a * m / b;
            }
        }
    }
    printf("%f\n", ans);
    return 0;
}
