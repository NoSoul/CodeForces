#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    if(m <= n / 2) {
        if(m == 0) {
            puts("1");
        } else {
            printf("%d\n", m);
        }
    } else {
        printf("%d\n", n - m);
    }
    return 0;
}
