#include <stdio.h>

int main()
{
    int a, b, c, min;
    scanf("%d %d %d", &a, &b, &c);
    b /= 2;
    c /= 4;
    min = a;
    if(min > b) {
        min = b;
    }
    if(min > c) {
        min = c;
    }
    printf("%d\n", min * 7);
    return 0;
}
