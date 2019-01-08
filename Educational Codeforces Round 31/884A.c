#include <stdio.h>

int main()
{
    int n, t, a;
    scanf("%d %d", &n, &t);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a);
        t -= 86400 - a;
        if(t <= 0) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}
