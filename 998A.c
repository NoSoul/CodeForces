#include <stdio.h>

int main()
{
    int n, sum = 0;
    int a[10];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    if(n == 1) {
        puts("-1");
    } else if(n == 2) {
        puts(a[0] == a[1] ? "-1" : "1\n1\n");
    } else {
        puts("1");
        for(int i = 0; i < n; ++i) {
            if(a[i] * 2 != sum) {
                printf("%d\n", i + 1);
                break;
            }
        }
    }
    return 0;
}
