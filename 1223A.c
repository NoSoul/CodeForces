#include <stdio.h>

int main()
{
    int q, n;
    scanf("%d", &q);
    while(q--) {
        scanf("%d", &n);
        if(n < 4) {
            printf("%d\n", 4 - n);
        } else {
            printf("%d\n", n & 1);
        }
    }
    return 0;
}
