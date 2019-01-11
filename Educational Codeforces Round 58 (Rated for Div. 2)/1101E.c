#include <stdio.h>

void CheckSwap(int *a, int *b)
{
    if(*a > *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}

int main()
{
    int n;
    char type[2];
    scanf("%d", &n);
    int maxX = 0;
    int maxY = 0;
    while(n--) {
        scanf("%s", type);
        if(type[0] == '+') {
            int x, y;
            scanf("%d %d", &x, &y);
            CheckSwap(&x, &y);
            if(maxX < x) {
                maxX = x;
            }
            if(maxY < y) {
                maxY = y;
            }
        } else {
            int h, w;
            scanf("%d %d", &h, &w);
            CheckSwap(&h, &w);
            puts((maxX <= h && maxY <= w) ? "YES" : "NO");
        }
    }
    return 0;
}
