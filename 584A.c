#include <stdio.h>

int main()
{
    int n, t;
    scanf("%d %d", &n, &t);
    if(n == 1 && t == 10) {
        puts("-1");
    } else {
        printf("%d", t);
        --n;
        if(t == 10) {
            --n;
        }
        while(n--) {
            printf("0");
        }
        puts("");
    }
    return 0;
}
