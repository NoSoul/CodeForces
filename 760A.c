#include <stdio.h>

int main()
{
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int m, d;
    scanf("%d %d", &m, &d);
    printf("%d\n", (days[m] - 2 + d) / 7 + 1);
    days[m] -= d;
    return 0;
}
