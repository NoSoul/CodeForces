#include <stdio.h>

int main()
{
    int h, m;
    scanf("%02d:%02d", &h, &m);
    printf("%f %f\n", 360.0 * (h % 12) / 12 + 30.0 * m / 60, 360.0 * m / 60);
    return 0;
}
