#include <stdio.h>

int main()
{
    int T, l, r;
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &l, &r);
        printf("%d %d\n", l, 2 * l);
    }
    return 0;
}
