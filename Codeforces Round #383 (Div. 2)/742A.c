#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    int a[4] = {6, 8, 4, 2};
    scanf("%d", &n);
    if(n == 0) {
        puts("1");
    } else {
        printf("%d\n", a[n & 3]);
    }
    return 0;
}
