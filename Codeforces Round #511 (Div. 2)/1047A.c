#include <stdio.h>

int main()
{
    int a, b, c, n;
    scanf("%d", &n);
    a = 1;
    b = 1;
    c = n - 2;
    if(c % 3 == 0) {
        --c;
        ++b;
    }
    printf("%d %d %d\n", a, b, c);
    return 0;
}
