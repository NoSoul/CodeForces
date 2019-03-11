#include <stdio.h>
#include <math.h>

int main()
{
    int t, d;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &d);
        if(d * d < 4 * d) {
            puts("N");
        } else {
            double b = (sqrt(d * d - 4 * d) + d) / 2;
            double a = d - b;
            if(a > b) {
                printf("Y %.9f %.9f\n", a, b);
            } else {
                printf("Y %.9f %.9f\n", b, a);
            }
        }
    }
    return 0;
}
