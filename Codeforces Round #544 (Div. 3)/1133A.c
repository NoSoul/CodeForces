#include <stdio.h>

int main()
{
    int h1, m1, h2, m2;
    scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);
    m1 += h1 * 60;
    m2 += h2 * 60;
    m1 += (m2 - m1) / 2;
    printf("%02d:%02d\n", m1 / 60, m1 % 60);
    return 0;
}
