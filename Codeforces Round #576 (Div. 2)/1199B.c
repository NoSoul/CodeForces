#include <stdio.h>

int main()
{
    float h, l;
    scanf("%f %f", &h, &l);
    float x = (l * l + h * h) / (2 * h) - h;
    printf("%f\n", x);
    return 0;
}
