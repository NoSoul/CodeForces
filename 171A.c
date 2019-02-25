#include <stdio.h>

int main()
{
    int a1, a2, m;
    scanf("%d %d", &a1, &a2);
    m = 0;
    while(a2) {
        m *= 10;
        m += a2 % 10;
        a2 /= 10;
    }
    printf("%d\n", a1 + m);
    return 0;
}
