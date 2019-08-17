#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", n / 2 + 1);
    int x = 1, y = 1;
    printf("%d %d\n", x, y);
    for(int i = 1; i < n; ++i) {
        if(i & 1) {
            y += 1;
            printf("%d %d\n", x, y);
        } else {
            x += 1;
            printf("%d %d\n", x, y);
        }
    }
    return 0;
}
