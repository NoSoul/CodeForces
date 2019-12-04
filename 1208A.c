#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        int a[3], n;
        scanf("%d %d %d", &a[0], &a[1], &n);
        a[2] = a[0] ^ a[1];
        printf("%d\n", a[n % 3]);
    }
    return 0;
}
