#include <stdio.h>

int main()
{
    int x;
    scanf("%d", &x);
    for(int i = 1; i <= x; ++i) {
        for(int j = 1; j <= x; ++j) {
            if(j % i == 0 && i * j > x && i / j < x && j <= i) {
                printf("%d %d\n", i, j);
                return 0;
            }
        }
    }
    puts("-1");
    return 0;
}
