#include <stdio.h>

int main()
{
    int a, b, c, i;
    scanf("%d %d %d", &a, &b, &c);
    for(i = 0; i <= a; ++i) {
        if(b - i == c - a + i && (b - i) >= 0 && (c - a + i) >= 0) {
            printf("%d %d %d\n", i, b - i, a - i);
            return 0;
        }
    }
    printf("Impossible\n");
    return 0;
}
