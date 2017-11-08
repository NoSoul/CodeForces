#include <stdio.h>

int main()
{
    int k, a, b;
    scanf("%d %d %d", &k, &a, &b);
    if(a % k && !(b / k)) {
        puts("-1");
    } else if(b % k && !(a / k)) {
        puts("-1");
    } else {
        printf("%d\n", a / k + b / k);
    }
    return 0;
}
