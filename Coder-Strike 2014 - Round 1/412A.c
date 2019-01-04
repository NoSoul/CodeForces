#include <stdio.h>

int main()
{
    int n, k;
    char str[101];
    scanf("%d %d", &n, &k);
    scanf("%s", str);
    if(k <= n / 2) {
        for(int i = k; i > 1; --i) {
            puts("LEFT");
        }
        for(int i = 0; i < n; ++i) {
            printf("PRINT %c\n", str[i]);
            if(i != n - 1) {
                puts("RIGHT");
            }
        }
    } else {
        for(int i = k; i < n; ++i) {
            puts("RIGHT");
        }
        for(int i = n - 1; i >= 0; --i) {
            printf("PRINT %c\n", str[i]);
            if(i != 0) {
                puts("LEFT");
            }
        }
    }
    return 0;
}
