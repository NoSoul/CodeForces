#include <stdio.h>

int main()
{
    int n, a;
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &a);
        if(a & 1) {
            printf("%d ", a);
        } else {
            printf("%d ", a - 1);
        }
    }
    puts("");
    return 0;
}
