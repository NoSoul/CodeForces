#include <stdio.h>

int main()
{
    int table[6][3] = {
        {0, 1, 2},
        {1, 0, 2},
        {1, 2, 0},
        {2, 1, 0},
        {2, 0, 1},
        {0, 2, 1}
    };
    int n, x;
    scanf("%d %d", &n, &x);
    n %= 6;
    printf("%d\n", table[n][x]);
    return 0;
}
