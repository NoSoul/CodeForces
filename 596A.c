#include <stdio.h>

int main()
{
    int N, i, x, y;
    int x1, y1, x2, y2;
    x1 = y1 = x2 = y2 = -1001;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d %d", &x, &y);
        if(i == 0) {
            x1 = x;
            y1 = y;
        } else {
            if(x > x1) {
                x2 = x;
            } else if(x < x1) {
                x2 = x1;
                x1 = x;
            }
            if(y > y1) {
                y2 = y;
            } else if(y < y1) {
                y2 = y1;
                y1 = y;
            }
        }
    }
    if(x2 == -1001 || y2 == -1001) {
        puts("-1");
    } else {
        printf("%d\n", (y2 - y1) * (x2 - x1));
    }
    return 0;
}
