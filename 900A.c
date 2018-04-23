#include <stdio.h>

int main()
{
    int n, x, y, a, b;
    scanf("%d", &n);
    a = b = 0;
    while(n--) {
        scanf("%d %d", &x, &y);
        if(x > 0) {
            ++a;
        } else {
            ++b;
        }
    }
    puts((a <= 1 || b <= 1) ? "Yes" : "No");
    return 0;
}
