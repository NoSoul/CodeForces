#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    if(n < 3) {
        puts("No");
    } else {
        puts("Yes");
        printf("%d ", n / 2);
        for(int i = 2; i <= n; i += 2) {
            printf("%d ", i);
        }
        printf("\n%d ", n - n / 2);
        for(int i = 1; i <= n; i += 2) {
            printf("%d ", i);
        }
    }
    return 0;
}
