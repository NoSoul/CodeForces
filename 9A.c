#include <stdio.h>

int main()
{
    int Y, W, Max;
    scanf("%d %d", &Y, &W);
    Max = Y;
    if(W > Max) {
        Max = W;
    }
    Max = 6 - Max + 1;
    if(Max == 1 || Max == 5) {
        printf("%d/6\n", Max);
    } else if(Max == 2 || Max == 4) {
        printf("%d/3\n", Max / 2);
    } else if(Max == 3) {
        printf("1/2\n");
    } else {
        printf("1/1\n");
    }
    return 0;
}
