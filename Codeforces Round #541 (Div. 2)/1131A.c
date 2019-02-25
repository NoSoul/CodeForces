#include <stdio.h>

int main()
{
    int w1, h1, w2, h2;
    scanf("%d %d %d %d", &w1, &h1, &w2, &h2);
    printf("%d\n", w1 + 2 + 2 * h1 + (w1 + 2 - w2) + (h2 - 1) * 2 + w2 + 2);
    return 0;
}
