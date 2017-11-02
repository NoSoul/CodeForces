#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    if(n < 2) {
        printf("%d\n", -1);
    } else {
        printf("%d %d %d\n", n, n + 1, n * (n + 1));
    }
    return 0;
}
