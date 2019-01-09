#include <stdio.h>


int main()
{
    int r, g, b;
    scanf("%d %d %d", &r, &g, &b);
    int time = 0;
    while(1) {
        if(r <= 0 && g <= 0 && b <= 0) {
            break;
        }
        if(time % 3 == 0) {
            r -= 2;
        } else if(time % 3 == 1) {
            g -= 2;
        } else {
            b -= 2;
        }
        ++time;
    }
    printf("%d\n", time + 30 - 1);
    return 0;
}
