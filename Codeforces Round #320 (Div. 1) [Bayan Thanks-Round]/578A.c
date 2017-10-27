#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    if(a == b) {
        printf("%.9f\n", 1.0 * a);
        return 0;
    }
    a += b;
    int left = 1;
    int right = a / 2;
    while(left < right - 1) {
        int mid = (left + right) >> 1;
        if(1.0 * a / (2 * mid) >= b) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    if(1.0 * a / (2 * right) >= b) {
        printf("%.9lf\n", 1.0 * a / (2 * right));
    } else if(1.0 * a / (2 * left) >= b) {
        printf("%.9lf\n", 1.0 * a / (2 * left));
    } else {
        puts("-1");
    }
    return 0;
}
