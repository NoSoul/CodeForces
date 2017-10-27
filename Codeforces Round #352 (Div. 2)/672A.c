#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    if(n < 10) {
        printf("%d\n", n);
    } else if(n < 190) {
        n -= 10;
        int num = n / 2 + 10;
        if(n & 1) {
            printf("%d\n", num % 10);
        } else {
            printf("%d\n", num / 10);
        }
    } else {
        n -= 190;
        int num = 100 + n / 3;
        if(n % 3 == 0) {
            printf("%d\n", num / 100);
        } else if(n % 3 == 1) {
            printf("%d\n", (num / 10) % 10);
        } else {
            printf("%d\n", num % 10);
        }
    }
    return 0;
}
