#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n;
    scanf("%d", &n);
    if(n & 1) {
        puts("YES");
        printf("1 ");
        for(int i = 1; i <= (n - 1) / 2; ++i) {
            printf("%d %d ", 4 * i, 4 * i + 1);
        }
        for(int i = 1; i <= (n - 1) / 2; ++i) {
            printf("%d %d ", 4 * i - 2, 4 * i + 1 - 2);
        }
        printf("%d\n", 2 * n);
    } else {
        puts("NO");
    }
    return 0;
}
