#include <stdio.h>

int main()
{
    int n, x, y, max = 1;
    scanf("%d", &n);
    while(n--) {
        scanf("%d %d", &x, &y);
        if(x + y > max) {
            max = x + y;
        }
    }
    printf("%d\n", max);
    return 0;
}
