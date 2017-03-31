#include <stdio.h>

int main()
{
    int a, b, ans = 1;
    scanf("%d %d", &a, &b);
    while(1) {
        a = 3 * a;
        b = 2 * b;
        if(a > b) {
            printf("%d\n", ans);
            break;
        }
        ++ans;
    }
    return 0;
}
